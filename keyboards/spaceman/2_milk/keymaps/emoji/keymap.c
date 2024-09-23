#include QMK_KEYBOARD_H
#include "os_detection.h"

enum tapdance_keycodes {
    TD_KEY_1,
    TD_KEY_2,
};

void dance_key_one (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        send_unicode_string("¯\\_(ツ)_/¯");
        tap_code(KC_ENTER);
        reset_tap_dance (state);
    } else if (state->count == 2) {
        unicode_input_mode_step();
        reset_tap_dance (state);
    }
}

void dance_key_two (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        send_unicode_string("ಠ_ಠ");
        tap_code(KC_ENTER);
        reset_tap_dance (state);
    } else if (state->count == 2) {
        send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
        tap_code(KC_ENTER);
        reset_tap_dance (state);
    } else if (state->count == 3) {
        send_unicode_string("╭∩╮(-_-)╭∩╮");
        tap_code(KC_ENTER);
        reset_tap_dance (state);
    } else if (state->count == 4) {
        send_unicode_string("(づ￣ ³￣)づ");
        tap_code(KC_ENTER);
        reset_tap_dance (state);
    } else if (state->count == 5) {
        send_unicode_string("(︺︹︺)");
        tap_code(KC_ENTER);
        reset_tap_dance (state);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_KEY_1] = ACTION_TAP_DANCE_FN(dance_key_one),
    [TD_KEY_2] = ACTION_TAP_DANCE_FN(dance_key_two),
};

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            set_unicode_input_mode(UNICODE_MODE_MACOS);
            break;
        case OS_LINUX:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;
        case OS_WINDOWS:
            set_unicode_input_mode(UNICODE_MODE_WINDOWS);
            break;
        case OS_UNSURE:
        default:
            // i do what i want
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TD(TD_KEY_1),
        TD(TD_KEY_2)
    ),
};
