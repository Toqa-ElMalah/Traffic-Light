/*
 * LED.c
 *
 * Created: 10/16/2023 5:13:06 PM
 *  Author: DELL
 */ 


#include "DIO.h"

void LED_vInit (unsigned char portname,unsigned char pinnumber){
	DIO_vsetPINDir(portname,pinnumber,1);
}

void LED_vTurnON (unsigned char portname,unsigned char pinnumber){
	DIO_write(portname,pinnumber,1);
}

void LED_vTurnOFF (unsigned char portname,unsigned char pinnumber){
	DIO_write(portname,pinnumber,0);
}

void LED_vToggle (unsigned char portname,unsigned char pinnumber){
	DIO_toggle(portname,pinnumber);
}

unsigned char LED_u8ReadStatus (unsigned char portname,unsigned char pinnumber){
	return DIO_u8read(portname,pinnumber);
}