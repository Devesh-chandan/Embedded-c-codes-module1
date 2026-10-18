#include <p18f4550.h>
#include "vector_relocate.h"

#define RS PORTBbits.RE0
#define RW PORTBbits.RE1
#define EN PORTBbits.RE2

void delay(unsigned int time)
{
    unsigned int i, j;

    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 1275; j++);
    }
}

void LCD_cmd(unsigned char command)
{
    PORTD = command;

    RS = 0;
    RW = 0;
    EN = 1;

    delay(250);

    EN = 0;

    delay(150);
}

void LCD_init(void)
{
    LCD_cmd(0x38);
    delay(100);

    LCD_cmd(0x01);
    delay(100);

    LCD_cmd(0x0E);
    delay(100);

    LCD_cmd(0x06);
    delay(100);

    LCD_cmd(0x80);
    delay(100);
}

void LCD_data(unsigned char data)
{
    PORTD = data;

    RS = 1;
    RW = 0;
    EN = 1;

    delay(150);

    EN = 0;

    delay(250);
}

void main(void)
{
    unsigned char i;
    unsigned char name[] = "Welcome to my college";

    ADCON1 = 0xFF;
    TRISD = 0x00;
    TRISE = 0x00;

    LCD_init();

    for (i = 0; name[i] != '\0'; i++)
    {
        LCD_data(name[i]);
    }

    while (1);
}