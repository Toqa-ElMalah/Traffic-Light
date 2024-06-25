#ifndef LED_H_
#define LED_H_

void LED_vInit (unsigned char portname,unsigned char pinnumber);
void LED_vTurnON (unsigned char portname,unsigned char pinnumber);
void LED_vTurnOFF (unsigned char portname,unsigned char pinnumber);
void LED_vToggle (unsigned char portname,unsigned char pinnumber);
unsigned char LED_u8ReadStatus (unsigned char portname,unsigned char pinnumber);


#endif /* LED_H_ */
