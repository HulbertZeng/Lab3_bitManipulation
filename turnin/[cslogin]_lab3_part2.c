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
    unsigned char ledlight = 0;
    /* Insert your solution below */
    while (1) {
	if(PINA > 0) {
	    ledlight += 0x20;
	} else if(PINA > 2) {
	    ledlight += 0x10;
	} else if(PINA > 4) {
	    ledlight += 0x08;
	} else if(PINA > 6) {
	    ledlight += 0x04;
	} else if(PINA > 9) {
	    ledlight += 0x02;
	} else if(PINA > 12) {
	    ledlight += 0x01;
	}
	if(PINA <= 4) {
	    ledlight += 0x40;
	}

	PORTC = ledlight;
    }
    return 1;
}
