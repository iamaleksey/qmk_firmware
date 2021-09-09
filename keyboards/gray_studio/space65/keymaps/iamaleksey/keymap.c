#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_65_ansi_blocker(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,          KC_HOME,
    KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
    ESC_EXT, A_LCTL , R_LOPT , S_LCMD , T_LSFT , KC_G   , KC_M   , N_RSFT , E_RCMD , I_ROPT , O_RCTL , KC_QUOT, KC_ENT ,                   KC_PGDN,
    KC_LSFT, KC_X   , KC_C   , KC_D   , KC_V   , KC_Z   , KC_K   , KC_H   , KC_COMM, TD_DOT , KC_SLSH,CAPS_WRD,                   KC_UP  , KC_END ,
    KC_LCTL, KC_LOPT, TAB_SYM,                            KC_SPC ,                            BSP_EXT, KC_ROPT,          KC_LEFT, KC_DOWN, KC_RGHT),

[_SYMBOL] = LAYOUT_65_ansi_blocker(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, _______, _______,          _______,
    KC_TILD, KC_EXLM, KC_PLUS, KC_LPRN, KC_RPRN, KC_AMPR, KC_PIPE, KC_MINS, KC_EQL , KC_UNDS, KC_ASTR, _______, _______,                   _______,
    _______, KC_AT  , KC_LCBR, KC_RCBR, KC_HASH, KC_DLR , KC_GRV , KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,                   _______, _______,
    _______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______),

[_EXTEND] = LAYOUT_65_ansi_blocker(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, KC_INS , KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_PGUP, PRV_WRD, KC_UP  , NXT_WRD, DEL_LNE, KC_BSPC, _______, _______,          _______,
    _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL , KC_BSPC, _______,                   _______,
    _______, CUT    , COPY   , PASTE  , REDO   , UNDO   , _______, LNE_BEG, _______, LNE_END, _______, _______,                   _______, _______,
    _______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______),

[_ADJUST] = LAYOUT_65_ansi_blocker(
    RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, _______, _______,          _______,
    _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______, _______, _______, _______, KC_F11 , _______, _______,                   _______,
    _______, RGB_SAD, RGB_HUD, RGB_VAD,RGB_RMOD, _______, _______, _______, _______, _______, KC_F12 , _______,                   _______, _______,
    _______, _______, _______,                            _______,                            _______, _______,          _______, _______, _______)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMBOL, _EXTEND, _ADJUST);
}

// CAPS_WORD: A "smart" Caps Lock key that only capitalizes the next identifier you type
// and then toggles off Caps Lock automatically when you're done.
void caps_word_enable(void) {
    caps_word_on = true;
    if (!(host_keyboard_led_state().caps_lock)) {
        tap_code(KC_CAPS);
    }
}

void caps_word_disable(void) {
    caps_word_on = false;
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

void process_caps_word(uint16_t keycode, const keyrecord_t *record) {
    if (!caps_word_on) { return; }

    // Update caps word state
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            // Earlier return if this has not been considered tapped yet
            if (record->tap.count == 0) { return; }
            // Get the base tapping keycode of a mod- or layer-tap key
            keycode = GET_TAP_KC(keycode);
            break;
        default:
            break;
    }

    switch (keycode) {
        // Keycodes to shift
        case KC_A ... KC_Z:
            if (record->event.pressed) {
                caps_word_enable();
            }
        // Keycodes that enable caps word but shouldn't get shifted
        case KC_MINS:
        case KC_BSPC:
        case KC_UNDS:
        case KC_PIPE:
        case CAPS_WRD:
            // If chording mods, disable caps word
            if (record->event.pressed && (get_mods() != MOD_LSFT) && (get_mods() != 0)) {
                caps_word_disable();
            }
            break;
        default:
            // Any other keycode should automatically disable caps
            if (record->event.pressed) {
                caps_word_disable();
            }
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_caps_word(keycode, record);
    switch (keycode) {
        case CAPS_WRD:
            // Toggle `caps_word_on`
            if (record->event.pressed) {
                if (caps_word_on) {
                    caps_word_disable();
                } else {
                    caps_word_enable();
                }
                return false;
            }
            break;
    }
    return true;
}

// Double dot to issue ". <one-shot-shift>" i.e. dot, space and capitalize next letter
void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        // Double tapping TD_DOT produces
        // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
        // This helps to quickly end a sentence and begin another one
        // without having to hit shift.
        case 2:
            /* Check that Shift is inactive */
            if (!(get_mods() & MOD_MASK_SHIFT)) {
                tap_code(KC_SPC);
                /* Internal code of OSM(MOD_LSFT) */
                add_oneshot_mods(MOD_BIT(KC_LSHIFT));
            } else {
                // send ">" (KC_DOT + shift → ">")
                tap_code(KC_DOT);
            }
            break;

        // Since `sentence_end` is called on each tap
        // and not at the end of the tapping term,
        // the third tap needs to cancel the effects
        // of the double tap in order to get the expected
        // three dots ellipsis.
        case 3:
            // remove the added space of the double tap case
            tap_code(KC_BSPC);
            // replace the space with a second dot
            tap_code(KC_DOT);
            // tap the third dot
            tap_code(KC_DOT);
            break;

        // send KC_DOT on every normal tap of TD_DOT
        default:
            tap_code(KC_DOT);
    }
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [_TD_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, NULL, NULL)
};
