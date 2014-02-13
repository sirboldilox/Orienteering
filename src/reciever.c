/***************************************************
 *  Reciever Program
 *  Chip: Atmel ATtiny44
 *  For help: www.avr-tutorials.com
 *
 *  Port Layout: (Subject to change)
 *
 *  PORTA:
 *    A0   : H Bridge enable
 *    A1   : H Bridge direction control
 *    A2-7 : Parallel ouput to PBASIC controller
 *
 *  PORTB:
 *    B2   : Serial input from transmission
 *    B0,1,3 : Debug
 *
 */
// Preset constants
#define DELAYREAD 100  // Delay for polling the input in ms
#define MOTOREN   0
#define MOTORDIR  1

// Define simple functions
#define MotorHigh() PORTA =|  ( 1 << MOTOREN )
#define MotorLow()  PORTA =& ~( 1 << MOTOREN )

#define MotorClck()     PORTA =|  ( 1 << MOTORDIR )
#define MotorAnticlck() PORTA =& ~( 1 << MOTORDIR )

// Headder for port I/O
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

// Prototypes
void waitForSignal();
void checkBit();

// Signal read in.
unsigned char signal[4];

int main()
{
    unsigned char i=0;

    DDRA = 0x00;        // portA -> output
    DDRB = 0xF;         // portB -> input

    // Main program cycle
    while(1)
    {
	// Wait for an input signal on PortB
        waitForSignal();
	signal[i] = PINB;

	// Read data
	for(unsigned char i=1;i<3;i++)
	{
	    waitForSignal();
	    signal[i] = PINB;
	}

	// Reset output
	PORTA = 0x00;

	// Decode data
	// Decode Motor
	if(checkBit(signal[0],2))
    	{
	    if(checkBit(signal[0],0))
	        MotorClck();
            else
	        MotorAntiClck();

            MotorHigh();
        }
	else
	    MotorLow();

       /* Decode and setup Servos
	*
	*  Input signal byte must first have leading 1 removed
	*	0x1010 => 0x0010	& with 0111 [ Dec 7 ]
	*
	*  Shift signal inputs to setup PORTA after motor pins.
	*  PORTA: 0x000000MM
	*	    ^^^		<-- Left shift by 7
	*	       ^^^      <-- Left shift by 2
	*/

        signal[1] =& 0x07;
        signal[2] =& 0x07;

	PORTA =| ( signal[1] << 2 );
	PORTA =| ( signal[2] << 5 );
    }
    return 0;
}

/*
 *  Checks is a set bit in a register is high
 *  Returns: 1 if set, 0 if not.
 */
char checkBit(char pass,char bit)
{
  pass = pass & (1 << bit);

  if(pass)
    return 1;

  return 0;
}

/*
 *  Waits in an infinite loop until a signal
 *  appears on PortB
 *
 */
void waitForSignal()
{
    // Setup delay
    _delay_ms(DELAYREAD);

    // Loop while PINB = 0
    while(!PINB);
}
