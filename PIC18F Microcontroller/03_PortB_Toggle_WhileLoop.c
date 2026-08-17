/*
 * Program 3: Toggle PORT B continuously (0x55 / 0xAA pattern)
 * Controller : PIC18F4550
 * Compiler   : MPLAB C18
 */

#include <p18f4550.h>

void main(void)
{
    TRISB = 0;          // Configure PORTB as output

    while (1)            // we can use for(;;) also
    {
        PORTB = 0x55;
        PORTB = 0xAA;
    }
}
