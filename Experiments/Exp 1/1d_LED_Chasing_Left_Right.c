#include <reg51.h>

#define LED P0
sbit EN = P1^0;

void delay(void)
{
    unsigned int j;

    for (j = 0; j < 50000; j++)
    {
        // Delay loop
    }
}

void main(void)
{
    unsigned int i;

    while (1)
    {
        if (EN == 1)
        {
            // LED chasing: LEFT TO RIGHT
            for (i = 0; i < 8; i++)
            {
                LED = 0x80 >> i;
                delay();
            }
        }
        else
        {
            // LED chasing: RIGHT TO LEFT
            for (i = 0; i < 8; i++)
            {
                LED = 0x01 << i;
                delay();
            }
        }
    }
}