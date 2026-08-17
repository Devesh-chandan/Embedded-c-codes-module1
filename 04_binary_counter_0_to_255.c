/*
 * File        : 04_binary_counter_0_to_255.c
 * Description : Displays a binary count from 0 to 255 on Port 0, with a
 *               delay between each increment.
 * Target MCU  : 8051
 * Compiler    : Keil uVision (C51)
 */

#include "reg51.h"

void msDelay(unsigned int itime);

void main(void)
{
    unsigned int z;

    for (z = 0; z <= 255; z++)
    {
        P0 = z;
        msDelay(400);
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
