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
char checkValues();
void encode();
void transmitt();

// Global Variables
char Achannel = 0;	// ADC Channel Select, keeps track of the current channel used.
char Acomplete = 0;     // ADC Complete, flagged to 1 when all 3 ADC operations are complete.
char Aout[3];		// ADC output array for Right/Left/Motor sliders		
char Atrans[3];		// ADC previous output for check comparison.

void main()
{
    DDRA = 0xFF;        // portA -> input
    DDRB = 0x0;         // portB -> output

    sei(); 		// Enable interupts
    setupADC();

    while(1)
    {
		runADC(Achannel);		    // Run ADC on A0, Interupt will then keep manage the
							        // Achannel variable and re-running the ADC

		while(Acomplete);		    // Wait for all ADC operations
	
		if(checkValues())		    // If slider has been moved encode & transmitt
	    {
		    char i=0;
		    for(i=0;i<3;i++)			// If difference copy new values to transmitt / prev out array
				Atrans[i] = Aout[i];

	        encode();
	        transmitt();
		}
		Acomplete = 0;
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
    ADCSRA = 0x8F;    // ADC Control & status A  (10001111)
    ADCSRB = 0x10;    // ADC Control & status B  (00010000)
    DIDR0  = 0x03;    // Digital input disable A (00000111)
    return;
}

/*
 *  runADC
 *
 *  Starts the ADC to read inputs from the 3 sliders.
 *
 */
void runADC(char channel)
{
    ADMUX = channel; 	// Select passed channel
    ADCSRA |= 0x40;	// Start ADC conversion	(01000000) 
    return;
}

/*
 *  ADC Interupt Routine
 *
 *  Store result in correct register when ADC complete and handles
 *   altering the Achannel variable and re-calling the runADC() function.
 *
 */
ISR(ADC_vect)
{
   Aout[Achannel] = ADCH;
   
   if (Achannel == 2)       // If Last channel done set flag and reset
   {
	Achannel = 0;
	Acomplete = 1;
   }
   else			   // Otherwise keep running.
   {
	Achannel++;
        runADC();
   }
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
char checkValues()
{
    char i=0;

    for(i=0;i<3;i++)
      if( Aout[i] != Atrans[i] )  // Check for difference
	return 1;
   
    return 0;
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
    // DEBUGGING CODE
    // Outputs a serial string of Left the Right the Motor values
    //  separated by a 1 second interval
    // Requires LED's on port B

    char i=0;
    for(i=0;i<3;i++)
	{
		// Not finished.
	}
    return;
}
