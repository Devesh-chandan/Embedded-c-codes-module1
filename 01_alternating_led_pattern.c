/*
 * File        : 01_alternating_led_pattern.c
 * Description : Continuously alternates the 8 LEDs connected to Port 1
 *               between the patterns 0x55 (01010101) and 0xAA (10101010),
 *               producing a blinking/alternating LED effect.
 * Target MCU  : 8051
 * Compiler    : Keil uVision (C51)
 */

#include <reg51.h>

void msDelay(unsigned int itime);

void main(void)
{
    while (1)                      /* repeat forever */
    {
        P1 = 0x55;
        msDelay(250);
        P1 = 0xAA;
        msDelay(250);
    }
}

/*
 * Function    : msDelay
 * Description : Generates an approximate delay using nested loops.
 * Parameter   : itime - delay multiplier
 */
void msDelay(unsigned int itime)
{
    unsigned int i, j;

    for (i = 0; i < itime; i++)
        for (j = 0; j < 1275; j++);
}
