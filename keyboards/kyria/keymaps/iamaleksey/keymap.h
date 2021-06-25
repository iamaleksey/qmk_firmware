#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK,
    _QWERTY,
    _WASD,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    WASD
};

// Home row mods (Colemak-DHm)
#define A_LCTL LCTL_T(KC_A)
#define R_LOPT LOPT_T(KC_R)
#define S_LCMD LCMD_T(KC_S)
#define T_LSFT LSFT_T(KC_T)
#define N_RSFT RSFT_T(KC_N)
#define E_RCMD RCMD_T(KC_E)
#define I_ROPT ROPT_T(KC_I)
#define O_RCTL RCTL_T(KC_O)

// Home row mods (QWERTY)
#define A_LCTL   LCTL_T(KC_A)
#define S_LOPT   LOPT_T(KC_S)
#define D_LCMD   LCMD_T(KC_D)
#define F_LSFT   LSFT_T(KC_F)
#define J_RSFT   RSFT_T(KC_J)
#define K_RCMD   RCMD_T(KC_K)
#define L_ROPT   ROPT_T(KC_L)
#define SCN_RTCL RCTL_T(KC_SCLN)

// Layer switching / mod taps
#define LWR_TAB LT(_LOWER, KC_TAB)
#define RSE_ENT LT(_RAISE, KC_ENT)
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

// Beginning of line / end of line
#define BOL LCMD(KC_LEFT)
#define EOL LCMD(KC_RGHT)

// Prev tab / next tab
#define PRV_TAB LCTL(LSFT(KC_TAB))
#define NXT_TAB LCTL(KC_TAB)
