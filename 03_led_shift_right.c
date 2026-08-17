/*
 * File        : 03_led_shift_right.c
 * Description : Starts with a single LED lit on Port 2 (0x80) and shifts
 *               it right, one position at a time, for 10 steps, repeating
 *               continuously.
 * Target MCU  : 8051
 * Compiler    : Keil uVision (C51)
 */

#include "reg51.h"

void msDelay(unsigned int itime);

void main(void)
{
    unsigned int z;

    while (1)
    {
        P2 = 0x80;
        for (z = 0; z <= 9; z++)
        {
            msDelay(400);
            P2 = P2 >> 1;
        }
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
