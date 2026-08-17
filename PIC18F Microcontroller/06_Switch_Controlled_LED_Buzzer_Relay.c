/*
 * Program 6: Switch-controlled LED pattern, Buzzer and Relay
 * Controller : PIC18F4550
 * Compiler   : MPLAB C18
 *
 * SW1 (RB4) -> Shift LED pattern on PORTD one way, buzzer & relay ON
 * SW2 (RB5) -> Shift LED pattern on PORTD the other way, buzzer & relay OFF
 */

#include <p18f4550.h>           // Include controller specific .h
#include "vector_relocate.h"    // Vector remapping for USB HID Bootloader

// Declarations
#define lrbit   PORTBbits.RB4   // SW1 interfaced to RB4
#define rlbit   PORTBbits.RB5   // SW2 interfaced to RB5
#define buzzer  PORTCbits.RC2   // Buzzer interfaced to RC2
#define relay   PORTCbits.RC1   // Relay interfaced to RC1

// Function prototype
void msdelay(unsigned int time);   // Function for delay

// Function definition
void msdelay(unsigned int time)    // Function for delay
{
    unsigned int i, j;

    for (i = 0; i < time; i++)
        for (j = 0; j < 710; j++); // Calibrated for a 1 ms delay in MPLAB
}

void main()                        // Main program
{
    unsigned char val = 0;         // Variable to latch the switch condition

    INTCON2bits.RBPU = 0;          // Activate internal pull-ups on PORTB
    ADCON1 = 0x0F;                 // Disable all analog inputs

    TRISBbits.TRISB4 = 1;          // Configure RB4 as input for sensing SW1
    TRISBbits.TRISB5 = 1;          // Configure RB5 as input for sensing SW2

    TRISCbits.TRISC1 = 0;          // Configure RC1 (relay) as output
    TRISCbits.TRISC2 = 0;          // Configure RC2 (buzzer) as output

    TRISD = 0x00;                  // Configure PORTD (LED) as output

    PORTD  = 0x00;                 // Initial value for LED
    buzzer = 0;                    // Initial value for buzzer
    relay  = 0;                    // Initial value for relay

    while (1)                      // Repeated operation
    {
        if (!(lrbit))               // Check whether SW1 is pressed
            val = 1;                 // Latch the status of switch SW1

        if (!(rlbit))               // Check whether SW2 is pressed
            val = 2;                 // Latch the status of switch SW2

        if (val == 1)
        {
            buzzer = 1;
            relay  = 1;
            PORTD  = PORTD >> 1;    // Shift right by 1 bit
            if (PORTD == 0x00)
                PORTD = 0x80;        // Make the MSB bit equal to 1
            msdelay(250);
        }

        if (val == 2)
        {
            buzzer = 0;
            relay  = 0;
            PORTD  = PORTD << 1;    // Shift left by 1 bit
            if (PORTD == 0x00)
                PORTD = 0x01;        // Make the LSB bit equal to 1
            msdelay(250);
        }
    }
}
