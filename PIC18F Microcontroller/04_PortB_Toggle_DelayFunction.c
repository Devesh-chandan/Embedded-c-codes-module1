/*
 * Program 4: Toggle PORT B using a custom delay function
 * Controller : PIC18F4550
 * Compiler   : MPLAB C18
 */

#include <p18f4550.h>

void delay(unsigned int);      // Function prototype

void main(void)
{
    TRISB = 0;                 // Configure PORTB as output

    while (1)
    {
        PORTB = 0x55;
        delay(250);
        PORTB = 0xAA;
        delay(250);
    }
}

void delay(unsigned int time)
{
    unsigned int i, j;

    for (i = 0; i < time; i++)
        for (j = 0; j < 165; j++);
}
