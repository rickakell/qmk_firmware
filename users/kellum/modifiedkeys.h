#pragma once

#include "keycodes.h"

// Window manipulation
#define TABL C(S(KC_TAB))
#define TABR C(KC_TAB)
#define WINB S(KC_TAB)

// General utility (Windows)
#define CUT C(KC_X)
#define CPY C(KC_C)
#define PST C(KC_V)
#define UND C(KC_Z)
#define RED C(KC_Y)
#define FND C(KC_F)
#define SAVE C(KC_S)
#define CMDP S(KC_INS) // paste in command prompt
#define WN_SNIP G(S(KC_S)) // windows snip shortcut (will copy to clipboard)
#define RC_CLIP G(A(KC_G)) // record clip using Windows game bar

// Art related
#define ZIN C(KC_PLUS)
#define ZOUT C(KC_MINS)
#define TFRM C(KC_T)
