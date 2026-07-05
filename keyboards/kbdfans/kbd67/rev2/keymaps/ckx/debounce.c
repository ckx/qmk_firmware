#include "debounce.h"
#include "timer.h"

#include <string.h>

#define ROW_SHIFTER ((matrix_row_t)1)
#define DEFAULT_DEBOUNCE 5
#define CHATTER_DEBOUNCE 15
#define FIVE_KEY_DEBOUNCE 20
#define PLUS_KEY_DEBOUNCE 10

static uint8_t      counters[MATRIX_ROWS][MATRIX_COLS];
static fast_timer_t last_time;
static bool         counters_need_update;

void debounce_init(uint8_t num_rows) {
    memset(counters, 0, sizeof(counters));
    counters_need_update = false;
}

void debounce_free(void) {}

static uint8_t debounce_time_for_key(uint8_t row, uint8_t col) {
    if (row == 0 && col == 5) { // 5
        return FIVE_KEY_DEBOUNCE;
    }

    if (row == 2 && col == 11) { // + (; key)
        return PLUS_KEY_DEBOUNCE;
    }

    if ((row == 0 && col == 4) || // 4
        (row == 3 && col == 10)) { // .
        return CHATTER_DEBOUNCE;
    }

    return DEFAULT_DEBOUNCE;
}

static bool update_counters(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, uint8_t elapsed_time) {
    bool changed = false;

    counters_need_update = false;
    for (uint8_t row = 0; row < num_rows; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            if (!counters[row][col]) {
                continue;
            }

            if (counters[row][col] <= elapsed_time) {
                counters[row][col] = 0;

                matrix_row_t mask = ROW_SHIFTER << col;
                matrix_row_t next = (cooked[row] & ~mask) | (raw[row] & mask);

                changed |= cooked[row] ^ next;
                cooked[row] = next;
            } else {
                counters[row][col] -= elapsed_time;
                counters_need_update = true;
            }
        }
    }

    return changed;
}

static void start_or_cancel_counters(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows) {
    for (uint8_t row = 0; row < num_rows; row++) {
        matrix_row_t delta = raw[row] ^ cooked[row];

        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            if (delta & (ROW_SHIFTER << col)) {
                if (!counters[row][col]) {
                    counters[row][col]  = debounce_time_for_key(row, col);
                    counters_need_update = true;
                }
            } else {
                counters[row][col] = 0;
            }
        }
    }
}

bool debounce(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, bool changed) {
    bool cooked_changed = false;
    bool updated_last   = false;

    if (counters_need_update) {
        fast_timer_t now          = timer_read_fast();
        fast_timer_t elapsed_time = TIMER_DIFF_FAST(now, last_time);

        last_time    = now;
        updated_last = true;

        if (elapsed_time > UINT8_MAX) {
            elapsed_time = UINT8_MAX;
        }

        if (elapsed_time > 0) {
            cooked_changed |= update_counters(raw, cooked, num_rows, elapsed_time);
        }
    }

    if (changed) {
        if (!updated_last) {
            last_time = timer_read_fast();
        }

        start_or_cancel_counters(raw, cooked, num_rows);
    }

    return cooked_changed;
}
