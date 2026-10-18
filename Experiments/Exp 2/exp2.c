#include <p18f4550.h>
#include "vector_relocate.h"

void main(void)
{
    unsigned int i;
    unsigned char val = 0;

    INTCON2bits.RBPU = 0;
    ADCON1 = 0x0F;
    TRISD = 0x00;

    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;

    TRISCbits.TRISC2 = 0;
    TRISCbits.TRISC1 = 0;

    PORTCbits.RC1 = 0;
    PORTCbits.RC2 = 0;

    while (1)
    {
        if (PORTBbits.RB0 == 0)
        {
            PORTCbits.RC1 = 1;
            PORTCbits.RC2 = 1;
            PORTD = 0x80;
            delay(100);

            for (i = 0; i < 8; i++)
            {
                PORTD = PORTD >> 1;
                delay(100);
            }
        }

        if (PORTBbits.RB1 == 0)
        {
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTD = 0x01;
            delay(100);

            for (i = 0; i < 8; i++)
            {
                PORTD = PORTD << 1;
                delay(100);
            }
        }
    }
}