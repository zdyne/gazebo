#pragma once

#include <stdint.h>

#include "Decl.h"
#include "Ops.h"

DECL int gz_engine_init(
    uint8_t (*get_next_byte)(void),
	int(*set_led)(int led, unsigned char r, unsigned char g, unsigned char b),
	void(*latch_leds)(void)
	);

DECL int gz_engine_run(void);
