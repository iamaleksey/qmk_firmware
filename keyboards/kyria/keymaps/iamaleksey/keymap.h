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
    CAPS_WRD = SAFE_RANGE,
    COLEMAK,
    QWERTY,
    WASD
};

// Home row mods (Colemak-DHm)
#define   A_LCTL LCTL_T(KC_A)
#define   R_LOPT LOPT_T(KC_R)
#define   S_LCMD LCMD_T(KC_S)
#define   T_LSFT LSFT_T(KC_T)
#define   N_RSFT RSFT_T(KC_N)
#define   E_RCMD RCMD_T(KC_E)
#define   I_ROPT ROPT_T(KC_I)
#define SCN_RCTL RCTL_T(KC_SCLN)

// Home row mods (QWERTY)
#define   A_LCTL LCTL_T(KC_A)
#define   S_LOPT LOPT_T(KC_S)
#define   D_LCMD LCMD_T(KC_D)
#define   F_LSFT LSFT_T(KC_F)
#define   J_RSFT RSFT_T(KC_J)
#define   K_RCMD RCMD_T(KC_K)
#define   L_ROPT ROPT_T(KC_L)
#define SCN_RCTL RCTL_T(KC_SCLN)

// Layer switching / mod taps
#define LWR_TAB LT(_LOWER, KC_TAB)
#define RSE_ENT LT(_RAISE, KC_ENT)
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

// Text navigation / manipulation
#define LNE_BEG LCMD(KC_LEFT)
#define LNE_END LCMD(KC_RGHT)
#define DEL_LNE LCMD(KC_BSPC)
#define PRV_WRD LOPT(KC_LEFT)
#define NXT_WRD LOPT(KC_RGHT)

// Undo / redo / cut / copy / paste
#define UNDO  LCMD(KC_Z)
#define REDO  LSFT(UNDO)
#define CUT   LCMD(KC_X)
#define COPY  LCMD(KC_C)
#define PASTE LCMD(KC_V)

// Prev tab / next tab
#define PRV_TAB LCTL(LSFT(KC_TAB))
#define NXT_TAB LCTL(KC_TAB)

// Caps word
bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);

// Tap dances
enum dances { _TD_Q, _TD_DOT };
#define TD_Q   TD(_TD_Q)
#define TD_DOT TD(_TD_DOT)
