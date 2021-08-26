#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_all(
	_______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,          KC_HOME,
	KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
	ESC_EXT, A_LCTL , R_LOPT , S_LCMD , T_LSFT , KC_G   , KC_M   , N_RSFT , E_RCMD , I_ROPT , O_RCTL , KC_QUOT, KC_ENT ,                   KC_PGDN,
	KC_LSFT, KC_X   , KC_C   , KC_D   , KC_V   , KC_Z   , KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,                   KC_UP  , KC_END ,
	KC_LCTL, KC_LOPT, TAB_SYM,                            KC_SPC ,                            BSP_EXT, KC_ROPT,          KC_LEFT, KC_DOWN, KC_RGHT),

    [_SYMBOL] = LAYOUT_all(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, _______, _______,          _______,
	KC_TILD, KC_EXLM, KC_PLUS, KC_LPRN, KC_RPRN, KC_AMPR, KC_PIPE, KC_MINS, KC_EQL , KC_UNDS, KC_ASTR, _______, _______,                   _______,
	_______, KC_AT  , KC_LCBR, KC_RCBR, KC_HASH, KC_DLR , KC_GRV , KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,                   _______, _______,
	_______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______),

    [_EXTEND] = LAYOUT_all(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______, KC_INS , KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_PGUP, PRV_WRD, KC_UP  , NXT_WRD, DEL_LNE, KC_BSPC, _______, _______,          _______,
	_______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL , KC_BSPC, _______,                   _______,
	_______, CUT    , COPY   , PASTE  , REDO   , UNDO   , _______, LNE_BEG, _______, LNE_END, _______, _______,                   _______, _______,
	_______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______),

    [_ADJUST] = LAYOUT_all(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RESET  ,
	_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, _______, _______,          _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F11 , _______, _______,                   _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12 , _______,                   _______, _______,
	_______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMBOL, _EXTEND, _ADJUST);
}
