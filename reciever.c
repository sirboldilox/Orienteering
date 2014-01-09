/***************************************************
 *  Reciever Program
 *  Chip: Atmel ATtiny44
 *  For help: www.avr-tutorials.com
 *
 *  Port Layout: (Subject to change)
 *
 *  PORTA:
 *    A1-7 : Parallel ouput to PBASIC controller
 *
 *  PORTB:
 *    B0   : Serial input from transmission
 *    B1-3 : Debug
 *
 */

// Headder for port I/O
#include <avr/io.h>
#include <avr/delay.h>

int main()
{
	DDRA = 0x00;		// portA -> output
	DDRB = 0xF;		// portB -> input

	while(1)
	{
		PORTB = 0x01;
		_delay_ms(500);
		PORTB = 0x00;
		_delay_ms(500);
	}
	return 0;
}


