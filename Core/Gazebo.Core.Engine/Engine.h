#pragma once

#include <stdint.h>

#include "Decl.h"
#include "Ops.h"

DECL int gz_engine_init(
    uint8_t (*get_next_byte)(void),
	int (*set_led)(int led, uint8_t r, uint8_t g, uint8_t b),
	void (*latch_leds)(void),
	void (*delay)(uint16_t ms)
	);

DECL int gz_engine_run(void);
