/*
 * Program 2: Toggle PORT B (software delay generated using a for loop)
 * Controller : PIC18F4550
 * Compiler   : MPLAB C18
 */

#include <p18f4550.h>

void main(void)
{
    unsigned int z;

    TRISB = 0;                     // Configure PORTB as output

    for (z = 0; z <= 50000; z++)   // unsigned int range is 0 to 65535
    {
        PORTB = 0x00;
        PORTB = 0xAA;
    }

    while (1);                     // Halt here
}
