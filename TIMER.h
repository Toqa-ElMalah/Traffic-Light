#ifndef TIMER_H_
#define TIMER_H_


void Timer_CTC_init_interrupt (void);
void Timerwave_NonPWM (void);
void Timerwave_PWM (void);
void Timerwave_PhasecorrectPWM (void);

#endif /* TIMER_H_ */
