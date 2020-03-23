#ifndef __PWM_H__
#define __PWM_H__


extern int PID, PWM_DianJi_L, PWM_DianJi_R;
extern int PWM_DuoJi;
extern int DuoJi_Left, DuoJi_Right; 

int PWM_Limit(int value,int limit);
int DuoJi_PWM_Limit(int value);

void PWM_allocation_init();
void PUTOUT_PWM();
void GET_DuoJi_PWM();
void GET_PWM();

#endif
