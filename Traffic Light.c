#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 8000000UL

#include "util/delay.h"
#include "LLED.h"
#include "Timer.h"
#include "lcd1.h"

volatile unsigned char counter=0;
//unsigned char green_counter=10;
//unsigned char yellow_counter=5;
//unsigned char red_counter=7;

int main(void)
{
	unsigned char green_counter=10;
	unsigned char yellow_counter=5;
	unsigned char red_counter=7;
	LED_vInit('D',0);
	LED_vInit('D',1);
	LED_vInit('D',2);
	LCD_vInit('A');
	Timer_CTC_init_interrupt();
	
    while(1)
    {
		green_counter=10;
		yellow_counter=5;
		red_counter=7;
		LCD_clearscreen('A');
		LCD_vSend_string('A',"remaining 10 sec");
		LED_vTurnON('D',0);
		while(green_counter>00){
			if(counter>=100){
				counter=0;
				green_counter--;
				LCD_movecursor('A',1,11);
				LCD_vSend_char('A',' ');
				LCD_vSend_char('A',green_counter+48);
    }
}
   
   _delay_ms(500);
   LED_vTurnOFF('D',0);
   LED_vTurnON('D',1);
   LCD_clearscreen('A');
   LCD_vSend_string('A',"remaining 5 sec");
  
     while(yellow_counter>00){
	     if(counter>=100){
		     counter=0;
		     yellow_counter--;
		     LCD_movecursor('A',1,11);
		     LCD_vSend_char('A',' ');
		     LCD_vSend_char('A',yellow_counter+48);
	     }
     }
	 
	  _delay_ms(500);
	  LED_vTurnOFF('D',1);
	  LED_vTurnON('D',2);
	  LCD_clearscreen('A');
	  LCD_vSend_string('A',"remaining 7 sec");
	  
	    while(red_counter>00){
		    if(counter>=100){
			  counter=0;
			  red_counter--;
			  LCD_movecursor('A',1,11);
			  LCD_vSend_char('A',' ');
			  LCD_vSend_char('A',red_counter+48);
		  }
	  }
	  
	  _delay_ms(500);
	  LED_vTurnOFF('D',2);
	  
	}
}	
	
ISR (TIMER0_COMP_vect){
	
	counter++;
}		  
