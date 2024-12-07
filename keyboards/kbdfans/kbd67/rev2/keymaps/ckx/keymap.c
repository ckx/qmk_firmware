/* Copyright 2018 'mechmerlin'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define EMDASH 0x2014 // —
#define COMET 0x2604 // ☄
#define SHINE 0x23E3 // ⏣
#define ARROW 0x27B3 // ➳

// 1. マクロ用のキーコード名の宣言
// https://www.taneyats.com/entry/qmk-ime-toggle
enum custom_keycodes {
    M_HNZN_TGL,    // IMEトグル用
    CKX_EMDASH,
    CKX_PARAN // Create open/close paranthesis  
};

// 2. マクロの実装
// https://www.taneyats.com/entry/qmk-ime-toggle
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_HNZN_TGL: {
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("`"));
            }
            return false;
        }
        // case CKX_PARAN: {
        //     if (record->event.pressed) {
        //         SEND_STRING("()");
        //     }
        //     return false;
        // }

        // case CKX_EMDASH: {
        //     if (record->event.pressed) {
        //         SEND_STRING("a");
        //     }
        //     return false;
        // }
    }
    return true;
};



// key overrides
const key_override_t ko_shift_esc = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_TILD);
const key_override_t ko_shift_2 = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_DQT);
const key_override_t ko_shift_6 = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_AMPR);
const key_override_t ko_shift_7 = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_QUOT);
const key_override_t ko_shift_8 = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_LPRN);
const key_override_t ko_shift_9 = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_RPRN);
const key_override_t ko_shift_0 = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_UNDS);
const key_override_t ko_shift_minus = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_EQL);
const key_override_t ko_shift_ins = ko_make_basic(MOD_MASK_SHIFT, KC_INS, KC_PAUS);
const key_override_t ko_shift_del = ko_make_basic(MOD_MASK_SHIFT, KC_DEL, KC_SCRL);
const key_override_t ko_shift_semicolon = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, KC_PLUS);
const key_override_t ko_shift_colon = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_ASTR);
const key_override_t ko_shift_pgup = ko_make_basic(MOD_MASK_SHIFT, KC_PGUP, KC_HOME);
const key_override_t ko_shift_pgdn = ko_make_basic(MOD_MASK_SHIFT, KC_PGDN, KC_END);

const key_override_t **key_overrides = (const key_override_t *[]){
    &ko_shift_esc,
    &ko_shift_2,
    &ko_shift_6,
    &ko_shift_7,
    &ko_shift_8,
    &ko_shift_9,
    &ko_shift_0,
    &ko_shift_minus,
    &ko_shift_ins,
    &ko_shift_del,
    &ko_shift_semicolon,
    &ko_shift_colon,
    &ko_shift_pgup,
    &ko_shift_pgdn,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Default layout
// NOTE: some shifted keys are overridden above.
[0] = LAYOUT_all(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_CIRC, KC_AT, KC_BSPC, KC_INS,\
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,\
  M_HNZN_TGL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_COLN, KC_ENT, KC_PGUP,\
  KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,\
  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(1), DM_PLY1, DM_RSTP, KC_NO, DM_REC1, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap (Base Layer) Default Layer
   * ,---------------------------------------------------------------.
   * |Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | ^ | @ |Bck|Ins|
   * |----------------------------------------------------------------|
   * |Tab  | q | w | e | r | t | y | u | i | o | p | [ | ] |  \   |Del|
   * |----------------------------------------------------------------|
   * |大文字| a | s | d | f | g | h | j | k | l | ; | : | Return  |PgUp|
   * |----------------------------------------------------------------|
   * |LShift | z | x | c | v | b | n | m | , | . | / |RShift  |Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Meta|Alt| Space   | MO1 |   Fn2    | Fn3 | Fn4 |Lef|Dow|Rght|
   * `----------------------------------------------------------------'
*/

/* Keymap (Base Layer) Shifted
   * ,----------------------------------------------------------------.
   * | ~ | ! | " | # | $ | % | & | ' | ( | ) | _ | = | ^ | @ |Bck|Paus|
   * |----------------------------------------------------------------|
   * |Tab  | Q | W | E | R | T | Y | U | I | O | P | { | } |Pipe |Scrl|
   * |----------------------------------------------------------------|
   * |大文字| A | S | D | F | G | H | J | K | L | + | * | Return  |Home|
   * |----------------------------------------------------------------|
   * |LShift | Z | X | C | V | B | N | M | < | > | ? |RShift  |Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Meta|Alt| Space   | MO1 |   MO2   | MO3 | MO4 |Lef|Dow|Rght|
   * `----------------------------------------------------------------'
*/


// MO(1) -- Fn keys and custom stuff.
[1] = LAYOUT_all(
  KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, UC(EMDASH), KC_BSPC, KC_INS,\
  KC_CAPS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_PSCR, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,\
  KC_GRAVE, KC_A, UC(SHINE), KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_COLN, KC_ENT, KC_MPLY,\
  KC_LSFT, KC_NO, KC_Z, KC_X, UC(COMET), KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_VOLU, KC_MUTE,\
  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(1), DM_PLY2, DM_RSTP, KC_NO, DM_REC2, KC_BRID, KC_VOLD, KC_BRIU),
};

/* Keymap (MO1 Layer) Fn Layer
   * ,----------------------------------------------------------------.
   * | ~ | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | — |Bck|Ins||
   * |----------------------------------------------------------------|
   * |Caps | q | w | e | r | t | y | u | i | o | p | [ | ] |  \   |Del|
   * |----------------------------------------------------------------|
   * |  `  | a | ⏣ | d | f | g | h | j | k | l | ; | : |  Enter  |Pause/Play|
   * |----------------------------------------------------------------|
   * |LShift | z | x | ☄ | v | b | n | m | , | . | / |RShift  |Vol↑|Mute|
   * |----------------------------------------------------------------|
   * |Ctrl|Meta|Alt| Space   | MO1 |   Fn2    | Fn3 | Fn4 |BrightDown|Vol↓|BrightDown|
   * `----------------------------------------------------------------'
*/

// void matrix_init_user(void) {
// }

// void matrix_scan_user(void) {

// }

// void led_set_user(uint8_t usb_led) {

// }
