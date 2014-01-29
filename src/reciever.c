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
 *    B2   : Serial input from transmission
 *    B0,1,3 : Debug
 *
 */
// Preset constants
#define DATALENGTH = 8;  //
#define DATATIME = 10;	 // Time period of each data pulse in ms

// Headder for port I/O
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

// Prototypes
void decode();
void pushCommand();

int main()
{
    DDRA = 0x00;        // portA -> output
    DDRB = 0xF;         // portB -> input

    MCUCR = 1 << ISC01; // Falling edge triggering for INT0 interrupt
    GIMSK = 1 << INT0;  // enablt INT0 interrupt.
    sei()		// enable external interupts.

    while(1);      	// wait for input stream, let interrupt handle 
		   	// the rest.
    return 0;
}

/*
 *  Interrupt for pin B2, serial data stream.
 *
 */
ISR(INT0_vect)
{
   unsigned char i=0;
   GIMSK = 0 << INT0;   // Disable calling the interrupt whilst here.

   // Read the serial data stream... joys.
   for (i=0;i<DATALENGTH)
   {
     PINB ;
     _delay_ms(DATATIME);
   }

   GIMSK = 1 << INT0;   // Renable the interrupt.
}

/*
 * readStream
 *
 * Read an input stream from the reciever
 *
 * Note: this may be a function or an Interupt Service Routine (ISR)
 * depending on transmission implimentation.
 */

// To be implemented

/*
 *  decode
 *
 *  Decodes the stream read from the input to
 *  a command the parallax chip can understand
 */
void decode()
{
    return;
}

/*
 *  pushCommand
 *
 *  Puts a decode boe-bot command on the output
 *  register in parallel
 *
 *  Note: could just be one line, implemented as function
 *  incase additional operations or checks are needed later on.
 */
void pushCommand()
{
    return;
}
