/* Copyright 2015-2017 Jack Humbert
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

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _WASD,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Home row mods (QWERTY)
#define LCTL_A LCTL_T(KC_A)
#define LOPT_S LOPT_T(KC_S)
#define LCMD_D LCMD_T(KC_D)
#define SHFT_F LSFT_T(KC_F)
#define RSFT_J RSFT_T(KC_J)
#define RCMD_K RCMD_T(KC_K)
#define ROPT_L ROPT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

// Home row mods (Colemak-DHm)
#define LCTL_A LCTL_T(KC_A)
#define LOPT_R LOPT_T(KC_R)
#define LCMD_S LCMD_T(KC_S)
#define SHFT_T LSFT_T(KC_T)
#define RSFT_N RSFT_T(KC_N)
#define RCMD_E RCMD_T(KC_E)
#define ROPT_I LOPT_T(KC_I)
#define RCTL_O RCTL_T(KC_O)

// Layer switch / mod taps
#define LWR_TAB LT(_LOWER, KC_TAB)
#define RSE_ENT LT(_RAISE, KC_ENT)
#define QWERTY  DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)
#define WASD    DF(_WASD)
#define LOWER   DF(_LOWER)
#define RAISE   DF(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | \  | |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc ~| A/Ctl| S/Opt| D/Cmd| F/Sft|   G  |   H  | J/Sft| K/Cmd| L/Opt|;:/Ctl| '  " |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  | ,  < | .  > | /  ? | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctl  | Opt  | Cmd  |LwrTab| Space| Bksp |RseEnt| Cmd  | Opt  | Ctl  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_GESC, LCTL_A,  LOPT_S,  LCMD_D,  SHFT_F,  KC_G,    KC_H,    RSFT_J,  RCMD_K,  ROPT_L,  CTL_SCLN,KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    _______, KC_LCTL, KC_LOPT, KC_LCMD, LWR_TAB, KC_SPC,  KC_BSPC, RSE_ENT, KC_RCMD, KC_ROPT, KC_RCTL, _______
),

/* Colemak-DHm
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  | ;  : | \  | |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc ~| A/Ctl| R/Opt| S/Cmd| T/Sft|   G  |   M  | N/Sft| E/Cmd| I/Opt| O/Ctl| '  " |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  | ,  < | .  > | /  ? | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctl  | Opt  | Cmd  |LwrTab| Space| Bksp |RseEnt| Cmd  | Opt  | Ctl  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    KC_GESC, LCTL_A,  LOPT_R,  LCMD_S,  SHFT_T,  KC_G,    KC_M,    RSFT_N,  RCMD_E,  ROPT_I,  RCTL_O,  KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
    _______, KC_LCTL, KC_LOPT, KC_LCMD, LWR_TAB, KC_SPC,  KC_BSPC, RSE_ENT, KC_RCMD, KC_ROPT, KC_RCTL, _______
),

/* WASD
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | \  | |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc ~|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ;  : | '  " |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  | ,  < | .  > | /  ? | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Opt  | Cmd  | Lower| Space| Bksp | Raise| Cmd  | Opt  | Ctrl |      |
 * `-----------------------------------------------------------------------------------'
 */
[_WASD] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    CTL_SCLN,KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    _______, KC_LCTL, KC_LOPT, KC_LCMD, LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_RCMD, KC_ROPT, KC_RCTL, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   !  |   +  |   (  |   )  |   #  |   |  |   -  |   =  |   _  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   $  |   @  |   {  |   }  |   &  |   `  |   [  |   ]  |   %  |   ^  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_EXLM, KC_PLUS, KC_LPRN, KC_RPRN, KC_HASH, KC_PIPE, KC_MINS, KC_EQL,  KC_UNDS, KC_ASTR, _______,
    _______, KC_DLR,  KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR, KC_GRV,  KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Prev | Play | Next |      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Vol- | Mute | Vol+ |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Togl | Sat+ | Hue+ | Bri+ | Mode+|      |QWERTY|COLEMK| WASD | F11  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Togl | Sat- | Hue- | Bri- | Mode-|      |      |      |      | F12  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______, QWERTY,  COLEMAK, WASD,    KC_F11,  _______,
    _______, RGB_TOG, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, KC_F12,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
