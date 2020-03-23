#ifndef __PWM_H__
#define __PWM_H__


extern int PID, PWM_DianJi_L, PWM_DianJi_R, PWM_DuoJi;

int PWM_Limit(int value,int limit);
void GET_PWM();
void PUTOUT_PWM();
void PWM_allocation_init();


#endif
