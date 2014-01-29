/***************************************************
 *  Test Program - Fast ADC without indicators
 *  Chip: Atmel ATtiny44
 *  For help: www.avr-tutorials.com
 */

// Headder for port I/O
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

/*  PIN CONFIGURATION
 *
 *  PA0 -> ADC0
 *
 *  PB0 -> GREEN  LED out
 *  PB1 -> RED    LED out
 *  PB2 -> YELLOW LED out
 *
 *
 *
 *
 */

void setADC();
void runADC();

int ADCout;

int main()
{
	sei(); // Enable interupts 
	DDRB = 0xF; // Set port B to outputs

	while(1)
	{
	  setADC();
	}
	return 0;
}

// Setup ADC registers and interupt
void setADC()
{
   ADMUX = 0x00; 			// Setup correct pin

   // Setup Enable, Interupt and Clock scalar
   ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);  
   DIDR0 = (1 << ADC0D);		// Disable digital input

   runADC();
}

// Start ADC
void runADC()
{
  
  ADCSRA |= (1 << ADSC);		// Run ADC
}

// Interupt for ADC complete
ISR(ADC_vect)
{
  int i=0;
  ADCout = ADCH; // Store result in temporary register. 

  PORTB = ~ADCout; // Display Result
  _delay_ms(2000);

  PORTB |= 0x4;
  _delay_ms(1000);

  for(i=0;i<ADCout;i++)
  {
    _delay_ms(250);
    PORTB &= 0xB;    // 1011B
    _delay_ms(250);
    PORTB |= 0x4;
  }

  PORTB &= 0xb;
  _delay_ms(250);
  runADC();
}

