/*	Author: lab
 *  Partner(s) Name: Hulbert Zeng
 *	Lab Section:021
 *	Assignment: Lab #3  Exercise #2
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
    DDRC = 0xFF; PORTC = 0x00;
	unsigned char levels = 0;
	unsigned char lowfuel = 0;
    /* Insert your solution below */
    while (1) {
	if((PINA & 0x0F) > 0) {
	    levels = levels | 0x20;
	}
	if((PINA & 0x0F) > 2) {
	    levels = levels | 0x10;
	}
	if((PINA & 0x0F) > 4) {
	    levels = levels | 0x08;
	}
	if((PINA & 0x0F) > 6) {
	    levels = levels | 0x04;
	}
	if((PINA & 0x0F) > 9) {
	    levels = levels | 0x02;
	}
	if((PINA & 0x0F) > 12) {
	    levels = levels | 0x01;
	}
	lowfuel = ((PINA & 0x0F) < 5) ? 0x40 : 0x00;

	PORTC = levels + lowfuel;
    }
    return 1;
}
