#include "modifiedkeys.h"

#include QMK_KEYBOARD_H

void delayed_modifier(
    uint64_t delay,
    uint16_t modifier,
    uint16_t keycode,
    keyrecord_t *record
) {
    register_code(modifier);
    wait_ms(delay / 2);
    register_code(keycode);
    unregister_code(keycode);
    wait_ms(delay / 2);
    unregister_code(modifier)
};

void delayed_modifiers(
    uint64_t delay,
    uint16_t modifier1,
    uint16_t modifier2,
    uint16_t keycode,
    keyrecord_t *record
) {
    register_code(modifier1);
    register_code(modifier2);
    wait_ms(delay / 2);
    register_code(keycode);
    unregister_code(keycode);
    wait_ms(delay / 2);
    unregister_code(modifier1)
    unregister_code(modifier2);
};
