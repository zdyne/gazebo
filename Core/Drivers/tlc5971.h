#pragma once

#include <stdint.h>

int tlc5971_set_led(int led, uint8_t r, uint8_t g, uint8_t b);
void tlc5971_latch_leds(void);
