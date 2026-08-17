/*
 * Program 5: Toggle only bit RB4 continuously
 * Controller : PIC18F4550
 * Compiler   : MPLAB C18
 */

#include <p18f4550.h>

void delay(unsigned int);      // Function prototype

#define mybit PORTBbits.RB4

void main(void)
{
    TRISBbits.TRISB4 = 0;      // Configure RB4 as output

    while (1)
    {
        mybit = 1;
        delay(250);
        mybit = 0;
        delay(250);
    }
}

void delay(unsigned int time)
{
    unsigned int i, j;

    for (i = 0; i < time; i++)
        for (j = 0; j < 165; j++);
}
