/*
 *  Reciever test.c
 *  Working!
 */

// Headder for port I/O
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#include "common.h"
/*  PIN CONFIGURATION
 *
 *
 *
 */

// Prototypes
//void debug_flashPort(port) (_delay_ms(100); port = 0xFF; _delay_ms(200); port=0x00;)
#define DELAY 99
char checkBit(char pass,char bit)
{
  pass = pass & (1 << bit);

  if(pass)
    return 1;

  return 0;
}

void read();
void trigger();

unsigned char sinput = 0;

int main()
{

    DDRA = 0xFF; // Set A0 as output
    DDRB = 0x00; // Set port B to inputs

    _delay_ms(1000);    // Setup pause 
    while(1)
    {
        read();
    }

}

void read()
{
    if(!checkBit(PINB,2))
    {
        sinput = 0x00;
        trigger();
    }   
  
}

void trigger()
{
    unsigned char i;
    
    for(i=0;i<8;i++)
    {
       if(checkBit(PINB,2))
         sinput++;
       
       _delay_ms(99);
    }
    
    while(!checkBit(PINB,2)); // wait for stop bit
    
    PORTA = sinput;
} 
