/*
*
*
* Author : khadb, luankn
*/
#include "stdio.h"
#include "avr.h"
#include "lcd.h"
#include "keypad.h"
#include "music.h"

char bufmsg[17];

int main(void)
{
	/* Replace with your application code */
	ini_avr();
	ini_lcd();

	clr_lcd();
	puts_lcd2("Hello");
	/*init time*/
	SET_BIT(DDRB, 3);
	while (1)
	{
		SET_BIT(PORTB, 3);
		wait_avrMicro(1000);
		CLR_BIT(PORTB, 3);
		wait_avrMicro(1000);
	}
}
