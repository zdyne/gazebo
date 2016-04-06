
#include <stdio.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#include "Engine.h"

#include "serial.h"
#include "sequence.h"

#include "Drivers/tlc5971.h"

static void delay(uint16_t ms);


int main(void)
{
  int i = 0;

  FILE serial_out = FDEV_SETUP_STREAM(serial_write, NULL, _FDEV_SETUP_WRITE);

  
  serial_init();
  stdout = &serial_out;

  // Setup memory

  gz_engine_init(get_next_sequence_basic,
				 tlc5971_set_led,
				 tlc5971_latch_leds,
				 delay);

  while (1)
	  {
		  printf("Hello, world!\n");
		  delay(1000);
	  }

  return 0;
}


static void delay(uint16_t ms)
{
	_delay_ms((double)ms);
}
