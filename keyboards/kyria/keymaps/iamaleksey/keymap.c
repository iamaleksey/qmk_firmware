#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 *  Base Layer: Colemak-DHm
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : | \  | |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | Esc ~| A/Ctl| R/Opt| S/Cmd| T/Sft|   G  |                              |   M  | N/Sft| E/Cmd| I/Opt| O/Ctl| '  " |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |      |      |  |      |      |   K  |   H  | ,  < | .  > | /  ? |      |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
 *                      |      |      | Tab/ | Space| Prev |  | Next | Bspc | Entr/|      |      |
 *                      |      |      | Lower|      | tab  |  | tab  |      | Raise|      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK] = LAYOUT(
      XXXXXXX, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                                     KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSLS,
      KC_GESC, A_LCTL , R_LOPT , S_LCMD , T_LSFT , KC_G   ,                                     KC_M   , N_RSFT , E_RCMD , I_ROPT , O_RCTL , KC_QUOT,
      XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
                                 XXXXXXX, XXXXXXX, LWR_TAB, KC_SPC , PRV_TAB, NXT_TAB, KC_BSPC, RSE_ENT, XXXXXXX, XXXXXXX
    ),

/*
 * Alt Base Layer: QWERTY
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | \  | |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | Esc ~| A/Ctl| S/Opt| D/Cmd| F/Sft|   G  |                              |   H  | J/Sft| K/Cmd| L/Opt|;:/Ctl| '  " |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | .  > | /  ? |      |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
 *                      |      |      | Tab/ | Space| Prev |  | Next | Bspc | Entr/|      |      |
 *                      |      |      | Lower|      | tab  |  | tab  |      | Raise|      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
      KC_GESC, A_LCTL , S_LOPT , D_LCMD , F_LSFT , KC_G   ,                                     KC_H   , J_RSFT , K_RCMD , L_ROPT ,SCN_RCLT, KC_QUOT,
      XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
                                 XXXXXXX, XXXXXXX, LWR_TAB, KC_SPC , PRV_TAB, NXT_TAB, KC_BSPC, RSE_ENT, XXXXXXX, XXXXXXX
    ),

/*
 * Alt Base Layer: WASD for gaming (vanilla QWERTY without mod-taps)
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | \  | |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | Esc ~|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | '  " |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | .  > | /  ? | Sft  |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
 *                      |      |  Alt | Lower| Space| Entr |  | Entr | Bspc | Raise| Alt  |      |
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_WASD] = LAYOUT(
      KC_TAB,  _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_A   , KC_S   , KC_D   , KC_F   , _______,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, _______,
      KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT,
                                 _______, KC_LALT, LOWER  , _______, KC_ENT , KC_ENT , _______, RAISE  , KC_RALT, _______
    ),

/*
 * Lower Layer: symbols and numbers
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |   !  |   +  |   (  |   )  |   #  |                              |   |  |   -  |   =  |   _  |   *  |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |   $  |   @  |   {  |   }  |   &  |      |      |  |      |      |   `  |   [  |   ]  |   %  |   ^  |      |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
      _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
      _______, KC_EXLM, KC_PLUS, KC_LPRN, KC_RPRN, KC_HASH,                                     KC_PIPE, KC_MINS, KC_EQL , KC_UNDS, KC_ASTR, _______,
      _______, KC_DLR , KC_AT  , KC_LCBR, KC_RCBR, KC_AMPR, _______, _______, _______, _______, KC_GRV , KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Raise Layer: media and navigation
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |      |      |      |      |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |      | Prev | Play | Next |      |                              | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |      | Vol- | Mute | Vol+ |      |      |      |  |      |      | BOL  | PgDn | PgUp | EOL  |      |      |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
 *                      | Mute |      |      |      |      |  |      |      |      |      |      |
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
      _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, _______, _______, _______, BOL    , KC_PGDN, KC_PGUP, EOL    , _______, _______,
                                 KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: RGB and base layer switching, function keys
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * | Reset|  F1  |  F2  |  F3  |  F4  |  F5  |                              |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      | Togl | Sat+ | Hue+ | Bri+ | Mode+|                              |      |QWERTY|COLEMK| WASD |  F11 |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      | Togl | Sat- | Hue- | Bri- | Mode-|      |      |  |      |      |      |      |      |      |  F12 |      |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      RESET  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10, _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, QWERTY , COLEMAK, WASD   , KC_F11, _______,
      _______, RGB_TOG, RGB_SAD, RGB_HUD, RGB_VAD,RGB_RMOD, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef ENCODER_ENABLE
void encoder_scroll_down_up(bool clockwise) {
    if (clockwise) { tap_code(KC_PGDN); }
    else           { tap_code(KC_PGUP); }
}

void encoder_volume_up_down(bool clockwise) {
    if (clockwise) { tap_code(KC_VOLU); }
    else           { tap_code(KC_VOLD); }
}

void encoder_history_redo_undo(bool clockwise) {
    if (clockwise) { tap_code16(LCTL(KC_R)); }
    else           { tap_code  (KC_U);       }
}

void encoder_zoom_in_out(bool clockwise) {
    if (clockwise) { tap_code16(LCMD(KC_EQL )); }
    else           { tap_code16(LCMD(KC_MINS)); }
}

void left_encoder_update(uint8_t layer, bool clockwise) {
    switch (layer) {
        case _RAISE:
            encoder_volume_up_down(clockwise);
            break;
        default:
            encoder_scroll_down_up(clockwise);
    }
}

void right_encoder_update(uint8_t layer, bool clockwise) {
    switch (layer) {
        case _LOWER:
            encoder_zoom_in_out(clockwise);
            break;
        default:
            encoder_history_redo_undo(clockwise);
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);
    if      (index == 0) {  left_encoder_update(layer, clockwise); }
    else if (index == 1) { right_encoder_update(layer, clockwise); }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case COLEMAK:
        set_single_persistent_default_layer(_COLEMAK);
        return false;
    case QWERTY:
        set_single_persistent_default_layer(_QWERTY);
        return false;
    case WASD:
        set_single_persistent_default_layer(_WASD);
        return false;
    }

    return true;
}
