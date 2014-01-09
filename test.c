/***************************************************
 *  Test Program - Blink LED
 *  Chip: Atmel ATtiny44
 *  For help: www.avr-tutorials.com
 */

// Headder for port I/O
#include <avr/io.h>
#include <avr/delay.h>

int main()
{
	DDRB = 0x00;		//configure portB as output

	while(1)
	{
		PORTB = 0x01;
		_delay_ms(500);
		PORTB = 0x00;
		_delay_ms(500);
	}
	return 0;
}


