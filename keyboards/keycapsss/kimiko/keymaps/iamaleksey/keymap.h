#include QMK_KEYBOARD_H

enum layers { _QWERTY, _RAISE };

// Layer switching
#define RAISE MO(_RAISE)

// Left-only layout macro
#define LEFT( \
    L00, L01, L02, L03, L04, L05,      \
    L10, L11, L12, L13, L14, L15,      \
    L20, L21, L22, L23, L24, L25,      \
    L30, L31, L32, L33, L34, L35, L40, \
              L41, L42, L43, L44, L45  \
    ) \
    { \
        { L00    , L01    , L02    , L03    , L04    , L05     }, \
        { L10    , L11    , L12    , L13    , L14    , L15     }, \
        { L20    , L21    , L22    , L23    , L24    , L25     }, \
        { L30    , L31    , L32    , L33    , L34    , L35     }, \
        { L41    , L42    , L43    , L44    , L45    , L40     }, \
        { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
        { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
        { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
        { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
        { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }  \
    }

