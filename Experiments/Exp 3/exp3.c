#include <p18f4550.h>
#include "vector_relocate.h"
#define lrbit PORTBbits.RB0
#define rlbit PORTBbits.RB1
#define buzzer PORTDbits.RD7
#define relay PORTCbits.RC2

void msdelay(unsigned int time){
unsigned int i,j;
for(i=0;i<time;i++)
for(j=0;j<720;j++);
}

void main(){
unsigned char val=0;
	INTCON2bits.RBPU=0;
	ADCON1=0x0F;

	TRISBbits.TRISB0=1;
	TRISBbits.TRISB1=1;

	TRISDbits.TRISD7=0;
	TRISCbits.TRISC2=0;

	TRISD=0x00;
	PORTD=0x00;
	buzzer=0;
	relay=0;
while(1){
	if(!(lrbit))
	val=1;
	if(!(rlbit))
	val=2;

	if(val==1){
		buzzer=1;
		relay=1;
		PORTD=PORTD>>1;

		if(PORTD==0x00)
		PORTD=0x80;
		msdelay(250);
	}

	if(val==2){
		buzzer=0;
		relay=0;
		PORTD=PORTD<<1;
		if(PORTD==0x00)
		PORTD=0x01;
		msdelay(250);
	}
}
}
