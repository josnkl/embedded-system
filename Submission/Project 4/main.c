/*
* p4_Voltmeter.c
*
*/

#include <avr/io.h>
#include "avr.h"
#include "lcd.h"
#include "keypad.h"
#include "voltmeter.h"

int main(void)
{
	//Set all port A to input
	DDRA = 0x00;
	
	ini_avr();
	ini_lcd();
	ini_meter();
	unsigned short volt = 0;
	while (1)
	{
		//start meter Key A
		if(get_key() == 4){
			while(1){
				//Reset meter B
				if(get_key() == 8){
					ini_meter();
					break;
				}
				
				++count;
				//A2D is 1023 max at 5Volt
				volt = ((float)get_A2D()/ 1023.0 * 5.0) * 100;
				
				//1st time reading data
				if(count == 1){
					minVol = volt;
					maxVol = volt;
				}
				
				currVol = volt;
				//Calculate min
				if (currVol < minVol){
					minVol = currVol;
				}
				
				//Calculate max
				if(currVol > maxVol){
					maxVol = currVol;
				}
				
				total += volt;
				avgVol = total/count;
				
				displayAvgVol();
				displayCurrVol();
				displayMaxVol();
				displayMinVol();
				
				//wait 500ms
				wait_avr(500);
			}
		}
	}
}