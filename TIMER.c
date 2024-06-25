/*
 * TIMER.c
 *
 * Created: 10/26/2023 12:00:49 AM
 *  Author: DELL
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>
#include "std_macrous.h"

void Timer_CTC_init_interrupt (void){
	SET_BIT(TCCR0,WGM01);
	OCR0 = 80;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	sei();
	SET_BIT(TIMSK,OCIE0);
}

void Timerwave_NonPWM (void){
	
	SET_BIT(DDRB,3); //OC0 as output
	SET_BIT(TCCR0,WGM01); //CTC mode
	OCR0=64;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00); //TOGGLE OC0
}

void Timerwave_PWM (void){
	
	SET_BIT(DDRB,3); //OC0 as output
	SET_BIT(TCCR0,WGM00); //PWM mode
	SET_BIT(TCCR0,WGM01); //PWM mode
	OCR0=64;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	/*non_inverting mode
	SET_BIT(TCCR0,COM01); */
	
}

void Timerwave_PhasecorrectPWM (void){
	
	SET_BIT(DDRB,3); //OC0 as output
	SET_BIT(TCCR0,WGM00); //Phase correct PWM mode
	OCR0=64;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	/*clear OC0 up counting,set OC0 down counting
	SET_BIT(TCCR0,COM01); */
}