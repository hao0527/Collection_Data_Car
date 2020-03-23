#include "headfile.h"

int I_Error_0=0,Accumulate_0=0,D_Error_0=0,Last_Error_0=0;
int I_Error_1=0,Accumulate_1=0,D_Error_1=0,Last_Error_1=0;
int I_Error_2=0,Accumulate_2=0,D_Error_2=0,Last_Error_2=0;
int I_Error_SPEED=0,incremen_SPEED=0,Next_Error_SPEED=0,Last_Error_SPEED=0,SPEED=0;       //增量式速度环
int I_Error_speed=0,Accumulate_speed=0,D_Error_speed=0,Last_Error_speed=0,speed=0;        //位置式速度环
    

int PID_Limit(int value,int limit)              //对value限幅在（-limit，limit）范围
{
    value = value >  limit ?  limit : value;
    value = value < -limit ? -limit : value;
    return (int)value;
}

//直线 和 转小弯
int Pid_Count_0(int aim,float proportion,float integral,float differential,float practical)//目标值，比例系数，积分系数，微分系数，当前实际值
{
    I_Error_0 = aim - practical;               //偏差
    Accumulate_0 += I_Error_0;                 //偏差累计
    if(Accumulate_0 > 1000) Accumulate_0=1000; //积分限幅
    else if(Accumulate_0<-1000)Accumulate_0=-1000;
    D_Error_0 = I_Error_0 - Last_Error_0;
    Last_Error_0 = I_Error_0;
    return (int)(proportion*I_Error_0 + integral*Accumulate_0 + differential*D_Error_0);
}

//转直角弯(左转)
int Pid_Count_1(int aim,float proportion,float integral,float differential,float practical)//目标值，比例系数，积分系数，微分系数，当前实际值
{
    I_Error_1 = aim - practical;               //偏差
    Accumulate_1 += I_Error_1;                 //偏差累计
    if(Accumulate_1 > 1000) Accumulate_1=1000; //积分限幅
    else if(Accumulate_1<-1000)Accumulate_1=-1000;
    D_Error_1 = I_Error_1 - Last_Error_1;
    Last_Error_1 = I_Error_1;
    return (int)(proportion*I_Error_1 + integral*Accumulate_1 + differential*D_Error_1);
}

//转直角弯(右转)
int Pid_Count_2(int aim,float proportion,float integral,float differential,float practical)//目标值，比例系数，积分系数，微分系数，当前实际值
{
    I_Error_2 = aim - practical;               //偏差
    Accumulate_2 += I_Error_2;                 //偏差累计
    if(Accumulate_2 > 1000) Accumulate_2=1000; //积分限幅
    else if(Accumulate_2<-1000)Accumulate_2=-1000;
    D_Error_2 = I_Error_2 - Last_Error_2;
    Last_Error_2 = I_Error_2;
    return (int)(proportion*I_Error_2 + integral*Accumulate_2 + differential*D_Error_2);
}

//速度PID增量式
int Pid_Count_SPEED(int aim_SPEED,float proportion_SPEED,float integral_SPEED,float differential_SPEED,float practical_SPEED)//目标，比例系数，积分系数，微分系数，当前实际值
{
    I_Error_SPEED=aim_SPEED-practical_SPEED;
    incremen_SPEED= proportion_SPEED*(I_Error_SPEED-Next_Error_SPEED)+ integral_SPEED*I_Error_SPEED+ differential_SPEED*(I_Error_SPEED-2*Next_Error_SPEED+Last_Error_SPEED);
    practical_SPEED +=incremen_SPEED;
    Last_Error_SPEED =Next_Error_SPEED;                    //增量式PID不用对积分限幅
    Next_Error_SPEED =I_Error_SPEED;
    Last_Error_SPEED *= 0.7;
    Next_Error_SPEED *= 0.7;
    SPEED = practical_SPEED;
    
    SPEED = PID_Limit(SPEED , 9500);                       //对PID输出限幅
    return (int)SPEED;
}

//速度环PID位置式
int Pid_Count_speed(int aim_speed,float proportion_speed,float integral_speed,float differential_speed,float practical_speed)//目标，比例系数，积分系数，微分系数，当前实际值
{
    I_Error_speed = aim_speed - practical_speed;           //偏差
    Accumulate_speed += I_Error_speed;                     //偏差累计
    if(Accumulate_speed>7000)Accumulate_speed=7000;        //积分限幅
    else if(Accumulate_speed<-7000)Accumulate_speed=-7000;
    D_Error_speed = I_Error_speed - Last_Error_speed;
    Last_Error_speed = I_Error_speed;
    speed = proportion_speed*I_Error_speed + integral_speed*Accumulate_speed + differential_speed*D_Error_speed;
    
    speed = PID_Limit(speed , 9500);                       //对PID输出限幅
    return (int)speed;
}

