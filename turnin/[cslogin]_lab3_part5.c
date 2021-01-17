/*	Author: lab
 *  Partner(s) Name: Hulbert Zeng
 *	Lab Section:021
 *	Assignment: Lab #3  Exercise #5
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
    DDRB = 0xFE; PORTB = 0x01;
    DDRD = 0x00; PORTD = 0xFF;
    unsigned short weight = 0;
    unsigned char range = 0;
    /* Insert your solution below */
    while (1) {
	weight += PINB & 0x01;
	weight += PIND << 1;

	if(weight >= 70) {
	    range += 0x02;
	} else if(weight > 5) {
	    range += 0x04;
	}

	PORTB = PORTB || range;
    }
    return 1;
}
