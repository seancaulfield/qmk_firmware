#include "quantum.h"

// How long (in milliseconds) to wait between animation steps for each of the
// "Cycling rainbow" animations
const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = { 255, 127, 32 };

// How long (in milliseconds) to wait between animation steps for each of the
// "Swirling rainbow" animations
//const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 20};

__attribute__((weak))
void matrix_init_kb(void){
    setPinOutput(F4);
    writePinHigh(F4);
}

__attribute__((weak))
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        // writePin sets the pin high for 1 and low for 0.
        // In this example the pins are inverted, setting
        // it low/0 turns it on, and high/1 turns the LED off.
        // This behavior depends on whether the LED is between the pin
        // and VCC or the pin and GND.
        writePin(F4, !led_state.caps_lock);
    }
    return res;
}
