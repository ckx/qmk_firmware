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

// Defines custom keycodes for ckx portable & fake JIS layout
#define CKX_Q    S(KC_Q)
#define CKX_W    S(KC_W)
#define CKX_E    S(KC_E)
#define CKX_R    S(KC_R)
#define CKX_T    S(KC_T)
#define CKX_Y    S(KC_Y)
#define CKX_U    S(KC_U)
#define CKX_I    S(KC_I)
#define CKX_O    S(KC_O)
#define CKX_P    S(KC_P)

#define CKX_A    S(KC_A)
#define CKX_S    S(KC_S)
#define CKX_D    S(KC_D)
#define CKX_F    S(KC_F)
#define CKX_G    S(KC_G)
#define CKX_H    S(KC_H)
#define CKX_J    S(KC_J)
#define CKX_K    S(KC_K)
#define CKX_L    S(KC_L)

#define CKX_Z    S(KC_Z)
#define CKX_X    S(KC_X)
#define CKX_C    S(KC_C)
#define CKX_V    S(KC_V)
#define CKX_B    S(KC_B)
#define CKX_N    S(KC_N)
#define CKX_M    S(KC_M)

// key overrides
const key_override_t ko_shift_esc = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_TILD);
const key_override_t ko_shift_2 = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_DQT);
const key_override_t ko_shift_6 = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_AMPR);
const key_override_t ko_shift_7 = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_QUOT);
const key_override_t ko_shift_8 = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_LPRN);
const key_override_t ko_shift_9 = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_RPRN);
const key_override_t ko_shift_0 = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_UNDS);
const key_override_t ko_shift_minus = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_EQL);
const key_override_t ko_shift_at = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_GRV);
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
    &ko_shift_at,
    &ko_shift_ins,
    &ko_shift_del,
    &ko_shift_semicolon,
    &ko_shift_colon,
    &ko_shift_pgup,
    &ko_shift_pgdn,
    NULL
};



// unicode
enum unicode_names {
    EMDASH
};

// 1. マクロ用のキーコード名の宣言
// https://www.taneyats.com/entry/qmk-ime-toggle
enum custom_keycodes {
    M_HNZN_TGL,    // IMEトグル用
    CKX_PARAN // Create open/close paranthesis  
};

// 2. マクロの実装
// https://www.taneyats.com/entry/qmk-ime-toggle
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case M_HNZN_TGL:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("`"));
        }
        break;

    case CKX_PARAN:
        if (record->event.pressed) {
            SEND_STRING("()");
        }
        break;  
    }
    return true;
};

const uint32_t PROGMEM unicode_map[] = {
    [EMDASH]  = 0x2014  //
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap (Base Layer) Default Layer
   * ,---------------------------------------------------------------.
   * |Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | ^ | @ |Bck|Ins|
   * |----------------------------------------------------------------|
   * |Tab  | q | w | e | r | t | y | u | i | o | p | [ | ] |  \   |Del|
   * |----------------------------------------------------------------|
   * |大文字| a | s | d | f | g | h | j | k | l | ; | : |  Enter  |PgUp|
   * |----------------------------------------------------------------|
   * |LShift | z | x | c | v | b | n | m | , | . | / |RShift  |Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Meta|Alt| Space   | Fn1 |   Fn2   | Fn3 | Fn4 |Lef|Dow|Rght|
   * `----------------------------------------------------------------'
   */

  /* Keymap (Shift Layer) Default Layer
   * ,----------------------------------------------------------------.
   * | ~ | ! | " | # | $ | % | & | ' | ( | ) | _ | = | ^ | ` |Bck|Paus|
   * |----------------------------------------------------------------|
   * |Tab  | Q | W | E | R | T | Y | U | I | O | P | { | } |Pipe |Scrl|
   * |----------------------------------------------------------------|
   * |大文字 | A | S | D | F | G | H | J | K | L | + | * |Return  |Home|
   * |----------------------------------------------------------------|
   * |LShift | Z | X | C | V | B | N | M | < | > | ? |RShift  |Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Meta|Alt| Space   | Fn1 |   Fn2   | Fn3 | Fn4 |Lef|Dow|Rght|
   * `----------------------------------------------------------------'
   */

// Unshifted default layout
[0] = LAYOUT_all(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_CIRC, KC_AT, KC_BSPC, KC_INS,\
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,\
  M_HNZN_TGL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_COLN, KC_ENT, KC_PGUP,\
  KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,\
  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(2), KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT),

// // MO(1) -- Right shift layer
// [1] = LAYOUT_all(
//   KC_TILD, KC_EXLM, KC_DQT, KC_HASH, KC_DLR, KC_PERC, KC_AMPR, KC_QUOT, KC_LPRN, KC_RPRN, KC_UNDS, KC_EQL, KC_TILD, KC_GRV, KC_BSPC, KC_INS,
//   KC_EQL, CKX_Q, CKX_W, CKX_E, CKX_R, CKX_T, CKX_Y, CKX_U, CKX_I, CKX_O, CKX_P, KC_LCBR, KC_RCBR, KC_PIPE, KC_DEL,
//   KC_GRV, CKX_A, CKX_S, CKX_D, CKX_F, CKX_G, CKX_H, CKX_J, CKX_K, CKX_L, KC_PLUS, KC_ASTR, KC_ENT, KC_HOME,
//   KC_UNDS, KC_NO, CKX_Z, CKX_X, CKX_C, CKX_V, CKX_B, CKX_N, CKX_M, KC_LABK, KC_RABK, KC_QUES, KC_RSFT, KC_UP, KC_END,
//   KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(2), KC_LSFT, MO(3), KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT),

// MO(2) -- Fn keys and custom stuff.
[1] = LAYOUT_all(
  KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, X(EMDASH), KC_BSPC, KC_BRIU,\
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_PSCR, KC_LCBR, KC_RCBR, KC_BSLS, KC_BRID,\
  KC_CAPS, CKX_PARAN, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_CALC, KC_ASTR, KC_ENT, KC_MUTE,\
  DM_RSTP, KC_NO, DM_REC1, DM_PLY1, DM_REC2, DM_PLY2, KC_B, KC_N, KC_M, KC_LABK, KC_RABK, KC_QUES, KC_RSFT, KC_VOLU, KC_MPLY,\
  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(1), KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_MNXT),

};


// jp layout thing for later
// [0] = LAYOUT_all(
//   KC_ESC, JP_1, JP_2, JP_3, JP_4, JP_5, JP_6, JP_7, JP_8, JP_9, JP_0, JP_MINS, JP_CIRC, JP_BSLS, KC_BSPC, KC_INS,
//   KC_TAB, JP_Q, JP_W, JP_E, JP_R, JP_T, JP_Y, JP_U, JP_I, JP_O, JP_P, JP_LBRC, JP_RBRC, JP_YEN, KC_DEL,
//   JP_EISU, JP_A, JP_S, JP_D, JP_F, JP_G, JP_H, JP_J, JP_K, JP_L, JP_SCLN, JP_COLN, KC_ENT, KC_PGUP,
//   KC_LSFT, KC_NO, JP_Z, JP_X, JP_C, JP_V, JP_B, JP_N, JP_M, JP_COMM, JP_DOT, JP_SLSH, KC_RSFT, KC_UP, KC_PGDN,
//   KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(2), KC_LSFT, MO(3), KC_NO, KC_LEAD, KC_LEFT, KC_DOWN, KC_RGHT),

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
