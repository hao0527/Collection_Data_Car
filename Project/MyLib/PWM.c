#include "headfile.h"

int PID, PWM_DianJi_L, PWM_DianJi_R, PWM_DuoJi;


int PWM_Limit(int value,int limit)                  //对value限幅在（1，limit）范围
{
    value = value > limit ?  limit : value;
    value = value < 1 ? 1 : value;
    return (int)value;
}

void PWM_allocation_init()                          //配置PWM输出管脚
{
    pwm_init(PWM1_MODULE0_CHB_B23, 15000, 0);       //电机（频率给15kHz）最大占空比默认为50000
    pwm_init(PWM1_MODULE0_CHB_B23, 15000, 0);
    
    pwm_init(PWM1_MODULE0_CHB_B23, 200, 0);         //舵机
}  

void PUTOUT_PWM()                                   //输出PWM波
{
    pwm_duty(PWM1_MODULE0_CHB_B23, PWM_DianJi_L);   //电机
    pwm_duty(PWM1_MODULE0_CHB_B23, PWM_DianJi_R);
    
    pwm_duty(PWM1_MODULE0_CHB_B23, PWM_DuoJi);      //舵机
}

//判断不同状态，获取PWM占空比，实现从PID到PWM
void GET_PWM()
{
/*
    //直道PID
    if(fabs(Normalization1)<50)
    {
        PID=Pid_Count_0(0,6,0,20,Normalization1);
        if(fabs(Normalization1)<15)
            PID=Pid_Count_0(0,3,0,10,Normalization1);
        PID_Limit(2000);
        PWM_R = 4900 - PID;
        PWM_L = 5000 + PID;
    }
    
    //转弯PID
    if(fabs(Normalization1)>=50)
    {
        PID=Pid_Count_0(0,6,0,20,Normalization1);
        PID_Limit(2000);
        PWM_R = 3900 - PID;
        PWM_L = 4000 + PID;
        PWM_Limit(10000);
    }

    //直弯左转
    if(Normalization2 > 0)
    {
        //be();
        PID=Pid_Count_1(0,10,0,50,Normalization2);
        PID_Limit(3000);
        PWM_L = 4000 + PID*1.3;   //-这个
        PWM_R = 3900 - PID*1.3;
        PWM_Limit(10000);
    }
    
    //直弯右转
    if(Normalization2 < -0)
    {
        //be();
        PID=Pid_Count_1(0,10,0,50,Normalization2);
        PID_Limit(3000);
        PWM_L = 4000 + PID*1*1.3;
        PWM_R = 3900 - PID*1*1.3;   //-这个
        PWM_Limit(10000);
    }
    //跑飞

    if(L1==1&&L2==1&&R1==1&&R2==1)
    {
        //PWM_R = 1500;
        //PWM_L = 1500;
    }
    //入环
    if(diff1<-150&&L1>50)
    {
        bebebe();
     
        PWM_L = 1000;
        PWM_R = 3000;
        PUTOUT_PWM();
        pit_delay_ms(PIT2,500);
        PWM_L = 5000;
        PWM_R = 4000;
        PUTOUT_PWM();
        pit_delay_ms(PIT2,500);

    }
    
     //出环
    if(diff1>150&&R1>50)
    {
        be();
        PWM_L = 5000;
        PWM_R = 5400;
        PUTOUT_PWM();
        pit_delay_ms(PIT2,800);
    }

    //十字路
    else if(L2>230&&R2>230)
    {
        //be();
        PWM_L = 5000;
        PWM_R = 5000;
        PUTOUT_PWM();
        pit_delay_ms(PIT2,200);
    }
*/
}


