/***************************************************
 *  Controller Program
 *  Chip: Atmel ATtiny44
 *  For help: www.avr-tutorials.com
 *
 *  Port Layout: (Subject to change)
 *
 *  PORTA:
 *    A0   : ADC0 -> Left Hand slider input
 *    A1   : ADC1 -> Right Hand slider input
 *    A2   : ADC2 -> Scoop motor slider input
 *    A3-7 : Unused
 *
 *
 *  PORTB:
 *    B0-3 : Debug
 *
 */

// Headder for port I/O
#include <avr/io.h>
#include <avr/delay.h>

// Prototypes
void setupADC();
void runADC();
int checkValues();
void encode();
void transmitt();

int main()
{
	DDRA = 0xFF;		// portA -> input
	DDRB = 0x0;		// portB -> output

	setupADC();
	
	while(1)
	{
		runADC();
	
		if(checkValues())
		{
		    encode();
			transmitt();
		}
	}	
	return 0;
}

/*
 *  SetupADC
 *
 *  Setups up register values to enable the ADC
 */
void setupADC()
{
    return;
}

/*
 *  runADC
 *
 *  Starts the ADC to read inputs from the 3 sliders.
 *  
 */
void runADC()
{
    return;
}

/*
 *  checkValues
 *
 *  Checks if the values from the ADC are different to the 
 *  previous ones, to see if a slider has been changed.
 *
 *  Returns:
 *    1 if different
 *    0 if the same
 */
int checkValues()
{
    return;
}

/*
 *  encode
 *
 *  Generates the binary number to be transmitted from the ADC 
 *  values.
 */
void encode()
{
    return;
}

/*
 *  transmitt
 *
 *  Outputs a serial stream to the transmission sub system.
 */
void transmitt()
{
    return;
}

