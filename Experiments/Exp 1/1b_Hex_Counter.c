#include <reg51.h>

sbit UP_DOWN = P1^0;

void delay(unsigned int time)
{
    unsigned int i, j;

    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 1275; j++)
        {
            // Delay loop
        }
    }
}

void main(void)
{
    unsigned char count;

    while (1)
    {
        if (UP_DOWN == 1)
        {
            // Hexadecimal UP counter
            for (count = 0x00; count <= 0xFF; count++)
            {
                P0 = count;
                delay(100);

                if (count == 0xFF)
                {
                    break;
                }
            }
        }
        else
        {
            // Hexadecimal DOWN counter
            for (count = 0xFF; count >= 0x00; count--)
            {
                P0 = count;
                delay(100);

                if (count == 0x00)
                {
                    break;
                }
            }
        }
    }
}