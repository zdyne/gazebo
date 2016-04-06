
#define BAUD 9600

#include <stdio.h>

#include <avr/io.h>

#include <util/setbaud.h>

#include "serial.h"


void serial_init(void)
{
  UBRR0H = UBRRH_VALUE;
  UBRR0L = UBRRL_VALUE;

  UCSR0A &= ~(_BV(U2X0));
  UCSR0B = _BV(TXEN0);
  UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
}

int serial_write(char c, FILE *stream)
{
  if (c == '\n')
	{
	  serial_write('\r', stream);
	}

  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;

  return 1;
}

