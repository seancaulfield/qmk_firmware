// Copyright 2021 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "os_detection.h"

enum {
  _BASE_LINUX,
  _BASE_MACOS,
  _FN_LINUX,
  _FN_MACOS,
};

#define FNLINUX MO(_FN_LINUX)
#define FNMACOS MO(_FN_MACOS)
#define RGB_RMD RGB_RMOD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E | R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \ │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Cap│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │   |Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   |Sft|   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Ctl│GUI│Alt│   │Spc│Mut│   │   |Spc|Alt│App│Ctl│   │Mo1|
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [_BASE_LINUX] = LAYOUT_all(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,       KC_8,     KC_9,        KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,       KC_I,     KC_O,        KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,       KC_K,     KC_L,        KC_SCLN,  KC_QUOT,  KC_ENT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,       KC_COMM,  KC_DOT,      KC_SLSH,  KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,             KC_SPC,   KC_SPC,     KC_MUTE,               KC_SPC,  KC_RALT,     FNLINUX,  KC_RGUI,  KC_RCTL
    ),
    [_BASE_MACOS] = LAYOUT_all(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,       KC_8,     KC_9,        KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,       KC_I,     KC_O,        KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,       KC_K,     KC_L,        KC_SCLN,  KC_QUOT,  KC_ENT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,       KC_COMM,  KC_DOT,      KC_SLSH,  KC_RSFT,
        KC_LCTL,  KC_LOPT,  KC_LCMD,             KC_SPC,   KC_SPC,     KC_MUTE,               KC_SPC,  KC_RCMD,     FNMACOS,  KC_ROPT,  KC_RCTL
    ),

    [_FN_LINUX] = LAYOUT_all(
        QK_BOOT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMD,  RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,     _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,            _______,  _______,     _______,            _______,  _______,  _______,  _______,            _______
    ),
    [_FN_MACOS] = LAYOUT_all(
        QK_BOOT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMD,  RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,     _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,            _______,  _______,     _______,            _______,  _______,  _______,  _______,            _______
    )

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) }
};
#endif

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            layer_move(_BASE_MACOS);
            break;
        case OS_LINUX:
        case OS_WINDOWS:
        case OS_UNSURE:
        default:
            layer_move(_BASE_LINUX);
            break;
    }

    return true;
}
