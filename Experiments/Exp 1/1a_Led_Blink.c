#include <reg51.h>

sbit UP_DOWN = P1^0;

void delay(unsigned int time)
{
    unsigned int i, j;

    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 1275; j++){}
        
    }
}

void main(void)
{
    unsigned char tens, units;
    while (1)
    {
        if (UP_DOWN == 1)
        {
            // BCD UP counter: 00 to 99
            for (tens = 0; tens < 10; tens++)
            {
                for (units = 0; units < 10; units++)
                {
                    P0 = (tens << 4) | units;
                    delay(100);
                }
            }
        }
        else
        {
            // BCD DOWN counter: 99 to 00
            for (tens = 9; tens < 10; tens--)
            {
                for (units = 9; units < 10; units--)
                {
                    P0 = (tens << 4) | units;
                    delay(100);

                    if (units == 0)
                    {
                        break;
                    }
                }

                if (tens == 0)
                {
                    break;
                }
            }
        }
    }
}