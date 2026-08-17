/*
 * File        : 05_alphabet_display_a_to_z.c
 * Description : Outputs the ASCII values of lowercase letters 'a' to 'z'
 *               sequentially on Port 0 (e.g. for driving a display), with
 *               a delay between each character.
 * Target MCU  : 8051
 * Compiler    : Keil uVision (C51)
 */

#include "reg51.h"

void msDelay(unsigned int itime);

void main(void)
{
    unsigned int z;

    for (z = 'a'; z <= 'z'; z++)
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
