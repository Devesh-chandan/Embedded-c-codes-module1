/*
 * File        : 00_basic_led_blink.c
 * Description : Toggles a single LED connected to pin P1.0 on and off —
 *               the most basic form of I/O port programming on the 8051.
 * Target MCU  : 8051
 * Compiler    : Keil uVision (C51)
 */

#include <reg51.h>

sbit led = P1 ^ 0; /* LED connected to P1.0 */

void delayMs(unsigned int delayCount);

void main(void)
{
    while (1) /* repeat forever */
    {
        led = 1; /* LED ON */
        delayMs(250);
        led = 0; /* LED OFF */
        delayMs(250);
    }
}

/*
 * Function    : delayMs
 * Description : Generates an approximate millisecond delay using
 *               nested loops.
 * Parameter   : delayCount - delay multiplier
 */
void delayMs(unsigned int delayCount)
{
    unsigned int outerLoop, innerLoop;

    for (outerLoop = 0; outerLoop < delayCount; outerLoop++)
        for (innerLoop = 0; innerLoop < 1275; innerLoop++)
            ;
}
