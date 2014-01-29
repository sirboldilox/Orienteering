/*
 *  Transmission test.c
 *  working!
 */

// Headder for port I/O
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

char checkBit(char pass,char bit)
{
  pass = pass & (1 << bit);

  if(pass)
    return 1;

  return 0;
}

#define DELAY 100
/*  PIN CONFIGURATION
 *
 *
 *
 */

// Prototypes
void send();
void read();

unsigned char input;
unsigned char packet = 0;

int main()
{
	sei(); // Enable interupts 
	DDRA = 0x00; // Set A0 as input
	DDRB = 0xFF; // Set port B to outputs

	while(1)
	{
	    PORTB = 0x01;                   // 1 otherwise.
	    if( checkBit(PINA,0) )          // Stream 10 01100100
        {
            if (packet == 0)
            {
                PORTB = 0x00;               // Start Bit trigger.
                _delay_ms(DELAY);
             
                PORTB = 0x00;      
                _delay_ms(DELAY);
                PORTB = 0x01;
                _delay_ms(DELAY);
                PORTB = 0x01;
                _delay_ms(DELAY);
                PORTB = 0x00;
                _delay_ms(DELAY);
                PORTB = 0x00;
                _delay_ms(DELAY);
                PORTB = 0x01;
                _delay_ms(DELAY);
                PORTB = 0x00;
                _delay_ms(DELAY);
                PORTB = 0x00;
                packet = 1;
            }
            else if(packet == 1)
            {
                PORTB = 0x00;               // Start Bit trigger.
                _delay_ms(DELAY);
               
                PORTB = 0x01;      
                _delay_ms(DELAY);
                PORTB = 0x01;
                _delay_ms(DELAY);
                PORTB = 0x01;
                _delay_ms(DELAY);
                PORTB = 0x01;
                _delay_ms(DELAY);
                PORTB = 0x00;
                _delay_ms(DELAY);
                PORTB = 0x01;
                _delay_ms(DELAY);
                PORTB = 0x00;
                _delay_ms(DELAY);
                PORTB = 0x00;
                packet = 0;
            }
        }
	}
}
