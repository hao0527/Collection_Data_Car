#ifndef __PID_H__
#define __PID_H__


int PID_Limit(int value,int limit);
int Pid_Count_0(int aim,float proportion,float integral,float differential,float practical);
int Pid_Count_1(int aim,float proportion,float integral,float differential,float practical);
int Pid_Count_2(int aim,float proportion,float integral,float differential,float practical);
int Pid_Count_speed(int aim_speed,float proportion_speed,float integral_speed,float differential_speed,float practical_speed);
int Pid_Count_SPEED(int aim_SPEED,float proportion_SPEED,float integral_SPEED,float differential_SPEED,float practical_SPEED);

#endif


