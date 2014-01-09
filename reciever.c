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

// Prototypes
void decode();
void pushCommand();

int main()
{
    DDRA = 0x00;        // portA -> output
    DDRB = 0xF;         // portB -> input

    while(1)
    {
        // wait for input stream
    }
    return 0;
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
