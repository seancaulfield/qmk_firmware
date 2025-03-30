/* Copyright 2024 Clear <Clear@163.com>
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
#include "quantum.h"
#include "ws2812.h"

/**************************** Matrix *********************************/
// 矩阵初始化之前执行
void keyboard_pre_init_kb(void) {
#ifdef RGB_MATRIX_SWITCH_PIN
    gpio_set_pin_output(RGB_MATRIX_SWITCH_PIN);
    gpio_write_pin(RGB_MATRIX_SWITCH_PIN, true);
#endif
}

// 初始化矩阵
void keyboard_post_init_kb(void) {
// 检查灯开关
#ifdef RGBLIGHT_ENABLE
    // Enable the LED layers
    rgblight_set_effect_range(0, RGBLIGHT_LED_COUNT);
#endif
    keyboard_post_init_user();
}

#ifdef RGB_MATRIX_ENABLE
// rgb动画锁定颜色
bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(RGB_INDEX_CAPS, RGB_WHITE);
    }

    if (host_keyboard_led_state().scroll_lock) {
        rgb_matrix_set_color(RGB_INDEX_SCROLL, RGB_WHITE);
    }

    if (layer_state_is(1)) {
        rgb_matrix_set_color(RGB_INDEX_FN, RGB_WHITE);
    }

    return false;
}
#endif

/*
 * Custom RGBLight driver is required, as the WS2812 LEDs for it are on a
 * different pin from the RGB matrix's WS2812 LEDs. Since the ws2812 driver
 * assumes a single, macro-defined pin for WS2812 usage, meaning we can't use
 * it for both RGB backlighting and RGB matrix.
 *
 * This mostly just steals the bitbang WS2812 code, as we don't have many LEDs
 * for the backlight and I want at least get something working, even if it's
 * not the most optimal.
 *
 */

#ifdef RGBLIGHT_ENABLE

#define WS2812_BITBANG_NOP_FUDGE (0.4)
#define WS2812_RGBLIGHT_DI_PIN (A2)

#ifndef WS2812_RES
#    define WS2812_RES (1000 * WS2812_TRST_US) // Width of the low gap between bits to cause a frame to latch
#endif

#define NUMBER_NOPS 6
#define CYCLES_PER_SEC (CPU_CLOCK / NUMBER_NOPS * WS2812_BITBANG_NOP_FUDGE)
#define NS_PER_SEC (1000000000L) // Note that this has to be SIGNED since we want to be able to check for negative values of derivatives
#define NS_PER_CYCLE (NS_PER_SEC / CYCLES_PER_SEC)
#define NS_TO_CYCLES(n) ((n) / NS_PER_CYCLE)

#define wait_ns(x)                                  \
    do {                                            \
        for (int i = 0; i < NS_TO_CYCLES(x); i++) { \
            __asm__ volatile("nop\n\t"              \
                             "nop\n\t"              \
                             "nop\n\t"              \
                             "nop\n\t"              \
                             "nop\n\t"              \
                             "nop\n\t");            \
        }                                           \
    } while (0)

void init_rgblight_custom(void);
void set_color_custom(int index, uint8_t r, uint8_t g, uint8_t b);
void set_color_all_custom(uint8_t r, uint8_t g, uint8_t b);
void flush_rgblight_custom(void);
void send_ws2812_byte(uint8_t b);

const rgblight_driver_t rgblight_driver = {
  .init          = init_rgblight_custom,
  .set_color     = set_color_custom,
  .set_color_all = set_color_all_custom,
  .flush         = flush_rgblight_custom,
};

/* Global array to hold backlight LED color info */
ws2812_led_t backlight_leds[RGBLIGHT_LED_COUNT];

void set_color_custom(int index, uint8_t r, uint8_t g, uint8_t b) {
  backlight_leds[index].r = r;
  backlight_leds[index].g = g;
  backlight_leds[index].b = b;
}

void set_color_all_custom(uint8_t r, uint8_t g, uint8_t b) {
  for (int i=0; i < RGBLIGHT_LED_COUNT; i++) {
    set_color_custom(i, r, g, b);
  }
}

void init_rgblight_custom(void) {
  palSetLineMode(WS2812_RGBLIGHT_DI_PIN, PAL_MODE_OUTPUT_PUSHPULL);
}

void flush_rgblight_custom(void) {
  chSysLock(); // Disable interrupts
  for (int i=0; i<RGBLIGHT_LED_COUNT; i++) {
    send_ws2812_byte(backlight_leds[i].g);
    send_ws2812_byte(backlight_leds[i].r);
    send_ws2812_byte(backlight_leds[i].b);
  }
  wait_ns(WS2812_RES);
  chSysUnlock(); // Re-enable interrupts
}

/*
 * Bitbang out the color information on the data line.
 */
void send_ws2812_byte(uint8_t b) {
  for (unsigned char bit=0; bit<8; bit++) {
    bool is_one = b & (1 << (7-bit));
    if (is_one) {
      gpio_write_pin_high(WS2812_RGBLIGHT_DI_PIN);
      wait_ns(WS2812_T1H);
      gpio_write_pin_low(WS2812_RGBLIGHT_DI_PIN);
      wait_ns(WS2812_T1L);
    } else {
      gpio_write_pin_high(WS2812_RGBLIGHT_DI_PIN);
      wait_ns(WS2812_T0H);
      gpio_write_pin_low(WS2812_RGBLIGHT_DI_PIN);
      wait_ns(WS2812_T0L);
    }
  }
}

#endif
