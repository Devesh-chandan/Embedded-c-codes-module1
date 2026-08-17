/*
 * File        : 06_two_digit_bcd_counter.c
 * Description : Generates a two-digit BCD count (00 to 99) on Port 1,
 *               where the upper nibble represents the tens digit and the
 *               lower nibble represents the units digit.
 * Target MCU  : 8051
 * Compiler    : Keil uVision (C51)
 */

#include "reg51.h"

void msDelay(unsigned int itime);

void main(void)
{
    unsigned int s, z;

    for (s = 0; s <= 9; s++)
        for (z = 0; z <= 9; z++)
        {
            P1 = (s << 4) | z;
            msDelay(500);
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
