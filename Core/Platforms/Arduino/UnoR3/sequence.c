
#include <stdint.h>

#include "Ops.h"

#include "sequence.h"


static uint8_t basic_post[] = {
	OP_DESCRIPTOR, 0x04,
	OP_COLOR, 0x00, 0xFF, 0x00,
	OP_ALL_ON,
	OP_DELAY, 0x00, 0x10,
	OP_COLOR, 0x00, 0x00, 0xFF,
	OP_ALL_ON,
	OP_DELAY, 0x00, 0x10,
	OP_COLOR, 0xFF, 0x00, 0x00,
	OP_ALL_ON,
	OP_DELAY, 0x00, 0x10,
	OP_COLOR, 0xFF, 0xFF, 0xFF,
	OP_ALL_ON,
	OP_HALT
};

uint8_t get_next_sequence_basic(void)
{	
	static int ip = 0;

	return basic_post[ip++];
}

