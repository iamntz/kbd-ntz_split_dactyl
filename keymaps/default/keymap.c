#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_6x6(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LT(5,KC_ESC), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, LT(5,KC_GRV), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(1,KC_SCLN), LT(3,KC_QUOT), KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, LT(4,KC_DOT), LT(5,KC_SLSH), RSFT_T(KC_BSLS), KC_LGUI, KC_TAB, LGUI(RCTL(KC_LEFT)), LGUI(RCTL(KC_RIGHT)), KC_LALT, LSFT_T(KC_SPC), RALT_T(KC_BSPC), LT(2,KC_ENT), LT(2,KC_ESC), MO(1), QK_LEAD, LT(3,KC_DEL), MO(3), MO(4), NK_TOGG, KC_NO),
	[1] = LAYOUT_6x6(KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LGUI(KC_N), KC_NO, RCTL(KC_MINS), RCTL(KC_PLUS), RCTL(KC_0), RGUI(KC_LEFT), RGUI(KC_DOWN), RGUI(KC_UP), RGUI(KC_RGHT), KC_NO, KC_NO, KC_LSFT, LGUI(KC_A), RSG(KC_S), KC_WBAK, KC_WFWD, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_LCTL, KC_TRNS, KC_LCBR, KC_RCBR, KC_LT, KC_GT, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_SLSH, KC_BSLS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_6x6(KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, RCTL(KC_PSCR), KC_GRV, KC_LCBR, KC_RCBR, KC_LT, KC_GT, KC_SLSH, KC_BSLS, KC_QUOT, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, LGUI(KC_SCLN), KC_INS, KC_BSPC, KC_TRNS, KC_ESC, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO),
	[3] = LAYOUT_6x6(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ACL2, KC_NO, KC_VOLU, KC_NO, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_BTN2, KC_NO, KC_NO, KC_ACL1, KC_MPRV, KC_MUTE, KC_MNXT, KC_MPLY, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_NO, KC_NO, KC_ACL0, KC_NO, KC_VOLD, KC_NO, KC_NO, KC_NO, KC_NO, RSFT(KC_COMM), RSFT(KC_DOT), KC_BTN3, KC_NO, LGUI(RCTL(KC_LEFT)), LGUI(RCTL(KC_RGHT)), KC_NO, KC_NO, KC_WH_U, KC_WH_D, KC_NO, KC_NO, KC_WFWD, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO),
	[4] = LAYOUT_6x6(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSA(KC_F10), LSA(KC_F9), KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, RCTL(KC_F2), KC_F9, KC_F8, KC_F7, RSFT(KC_F8), KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LALT(KC_F12), KC_NO, KC_NO, LCA(KC_F9), LALT(KC_F9), LALT(KC_F8), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO),
	[5] = LAYOUT_6x6(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_TAB), KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LGUI(RCTL(KC_LEFT)), LGUI(KC_TAB), LGUI(RCTL(KC_RIGHT)), LGUI(RCTL(KC_D)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_HOME), LSFT(KC_END), KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LGUI(RCTL(KC_F4)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};


