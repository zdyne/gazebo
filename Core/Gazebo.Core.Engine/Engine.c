
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "Engine.h"
#include "Ops.h"


struct color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
};


static uint8_t(*get_next_byte)(void);
static int(*set_led)(int led, unsigned char r, unsigned char g, unsigned char b);
static void(*latch_leds)(void);


static void delay(uint16_t ms);


int gz_engine_init(
	uint8_t(*get_next_byte_fn)(void),
	int(*set_led_fn)(int led, unsigned char r, unsigned char g, unsigned char b),
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
	struct color color_reg = { 0x00, 0x00, 0x00 };

	uint8_t n_leds = 0;
	uint8_t i;

	while (1)
	{
		enum op code = get_next_byte();

		switch (code)
		{
		case OP_HALT:
			return 0;
			break;

		case OP_DESCRIPTOR:
			n_leds = get_next_byte();
			break;

		case OP_COLOR:
			color_reg.r = get_next_byte();
			color_reg.g = get_next_byte();
			color_reg.b = get_next_byte();
			break;

		case OP_ALL_ON:
			for (i = 0; i < n_leds; i++)
			{
				set_led(i, color_reg.r, color_reg.g, color_reg.b);
			}
			latch_leds();
			break;

		case OP_DELAY:
		{
			uint8_t lowMs;
			uint8_t highMs;

			lowMs = get_next_byte();
			highMs = get_next_byte();
			delay((uint16_t)(highMs << 8) | lowMs);
		}
		break;

		default:
			break;
		}
	}

	return 0;
}

static void delay(uint16_t ms)
{
	clock_t target = ms + clock();

	while (target > clock())
	{
		/* Do nothing */
	}
}
