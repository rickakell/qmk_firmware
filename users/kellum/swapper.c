#include "swapper.h"

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger1,
    uint16_t trigger2,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger1) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            if (keycode == S(KC_TAB)) {
                register_code(KC_LSFT);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            if (keycode == S(KC_TAB)) {
                unregister_code(KC_LSFT);
            }
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (keycode == trigger2) {
    } else if (*active) {
        unregister_code(cmdish);
        *active = false;
    }
}

void update_swapper_back(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish1,
    uint16_t tabish2,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
){
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish1);
            register_code(tabish2);
        } else {
            unregister_code(tabish1);
            unregister_code(tabish2);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active) {
        unregister_code(cmdish);
        *active = false;
    }
}
