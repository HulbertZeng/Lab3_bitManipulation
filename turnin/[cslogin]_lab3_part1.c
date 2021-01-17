/*	Author: lab
 *  Partner(s) Name: Hulbert Zeng
 *	Lab Section:021
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <math.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char onescount = 0;
    /* Insert your solution below */
    while (1) {
	for(unsigned char i = 0; i < 8; ++i) {
	    onescount += PINA & (char)pow(2, i);
	    onescount += PINB & (char)pow(2, i);
	}

	PORTC = onescount;
    }
    return 1;
}
