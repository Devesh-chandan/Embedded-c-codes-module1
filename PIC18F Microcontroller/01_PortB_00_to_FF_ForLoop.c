/*
 * Program 1: Send values 00 to FF to PORT B (using a for loop)
 * Controller : PIC18F4550
 * Compiler   : MPLAB C18
 */

#include <p18f4550.h>

void main(void)
{
    unsigned char z;

    TRISB = 0;                 // Configure PORTB as output

    for (z = 0; z < 255; z++)  // unsigned char range is 0 to 255
    {
        PORTB = z;
    }

    while (1);                 // Halt here
}
