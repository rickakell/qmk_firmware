#pragma once

#include QMK_KEYBOARD_H

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,

    SW_WINF, // Switch to next window         (alt-tab)
    SW_WINB, // Switch to previous window     (alt-shift-tab)
    SW_LANG, // Switch to next input language (ctl-spc)

    TG_BRSH,
};
