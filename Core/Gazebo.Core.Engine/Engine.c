
#include <stdio.h>

#include "Engine.h"
#include "Ops.h"

static enum op (*get_next_byte)(void);
static int (*set_led)(int led, unsigned char r, unsigned char g, unsigned char b);
static void (*latch_leds)(void);

int gz_engine_init(
	enum op (*get_next_byte_fn)(void),
	int (*set_led_fn)(int led, unsigned char r, unsigned char g, unsigned char b),
	void(*latch_leds_fn)(void)
	)
{
	get_next_byte = get_next_byte_fn;
	set_led = set_led_fn;
	latch_leds = latch_leds_fn;

	return 0;
}

int gz_engine_run(void)
{
	while (1)
	{
		enum op code = get_next_byte();

		/* XXXX TEST CODE*/
		set_led(0, 0xFF, 0, 0);
		latch_leds();

		switch (code)
		{
		case HALT:
			return 0;
			break;

		default:
			break;
		}
	}

	return 0;
}