#include "headfile.h"

int I_Error_0=0,Accumulate_0=0,D_Error_0=0,Last_Error_0=0;
int I_Error_1=0,Accumulate_1=0,D_Error_1=0,Last_Error_1=0;
int I_Error_2=0,Accumulate_2=0,D_Error_2=0,Last_Error_2=0;
int I_Error_SPEED=0,incremen_SPEED=0,Next_Error_SPEED=0,Last_Error_SPEED=0,SPEED=0;       //����ʽ�ٶȻ�
int I_Error_speed=0,Accumulate_speed=0,D_Error_speed=0,Last_Error_speed=0,speed=0;        //λ��ʽ�ٶȻ�
    

int PID_Limit(int value,int limit)              //��value�޷��ڣ�-limit��limit����Χ
{
    value = value >  limit ?  limit : value;
    value = value < -limit ? -limit : value;
    return (int)value;
}

//ֱ�� �� תС��
int Pid_Count_0(int aim,float proportion,float integral,float differential,float practical)//Ŀ��ֵ������ϵ��������ϵ����΢��ϵ������ǰʵ��ֵ
{
    I_Error_0 = aim - practical;               //ƫ��
    Accumulate_0 += I_Error_0;                 //ƫ���ۼ�
    if(Accumulate_0 > 1000) Accumulate_0=1000; //�����޷�
    else if(Accumulate_0<-1000)Accumulate_0=-1000;
    D_Error_0 = I_Error_0 - Last_Error_0;
    Last_Error_0 = I_Error_0;
    return (int)(proportion*I_Error_0 + integral*Accumulate_0 + differential*D_Error_0);
}

//תֱ����(��ת)
int Pid_Count_1(int aim,float proportion,float integral,float differential,float practical)//Ŀ��ֵ������ϵ��������ϵ����΢��ϵ������ǰʵ��ֵ
{
    I_Error_1 = aim - practical;               //ƫ��
    Accumulate_1 += I_Error_1;                 //ƫ���ۼ�
    if(Accumulate_1 > 1000) Accumulate_1=1000; //�����޷�
    else if(Accumulate_1<-1000)Accumulate_1=-1000;
    D_Error_1 = I_Error_1 - Last_Error_1;
    Last_Error_1 = I_Error_1;
    return (int)(proportion*I_Error_1 + integral*Accumulate_1 + differential*D_Error_1);
}

//תֱ����(��ת)
int Pid_Count_2(int aim,float proportion,float integral,float differential,float practical)//Ŀ��ֵ������ϵ��������ϵ����΢��ϵ������ǰʵ��ֵ
{
    I_Error_2 = aim - practical;               //ƫ��
    Accumulate_2 += I_Error_2;                 //ƫ���ۼ�
    if(Accumulate_2 > 1000) Accumulate_2=1000; //�����޷�
    else if(Accumulate_2<-1000)Accumulate_2=-1000;
    D_Error_2 = I_Error_2 - Last_Error_2;
    Last_Error_2 = I_Error_2;
    return (int)(proportion*I_Error_2 + integral*Accumulate_2 + differential*D_Error_2);
}

//�ٶ�PID����ʽ
int Pid_Count_SPEED(int aim_SPEED,float proportion_SPEED,float integral_SPEED,float differential_SPEED,float practical_SPEED)//Ŀ�꣬����ϵ��������ϵ����΢��ϵ������ǰʵ��ֵ
{
    I_Error_SPEED=aim_SPEED-practical_SPEED;
    incremen_SPEED= proportion_SPEED*(I_Error_SPEED-Next_Error_SPEED)+ integral_SPEED*I_Error_SPEED+ differential_SPEED*(I_Error_SPEED-2*Next_Error_SPEED+Last_Error_SPEED);
    practical_SPEED +=incremen_SPEED;
    Last_Error_SPEED =Next_Error_SPEED;                    //����ʽPID���öԻ����޷�
    Next_Error_SPEED =I_Error_SPEED;
    Last_Error_SPEED *= 0.7;
    Next_Error_SPEED *= 0.7;
    SPEED = practical_SPEED;
    
    SPEED = PID_Limit(SPEED , 9500);                       //��PID����޷�
    return (int)SPEED;
}

//�ٶȻ�PIDλ��ʽ
int Pid_Count_speed(int aim_speed,float proportion_speed,float integral_speed,float differential_speed,float practical_speed)//Ŀ�꣬����ϵ��������ϵ����΢��ϵ������ǰʵ��ֵ
{
    I_Error_speed = aim_speed - practical_speed;           //ƫ��
    Accumulate_speed += I_Error_speed;                     //ƫ���ۼ�
    if(Accumulate_speed>7000)Accumulate_speed=7000;        //�����޷�
    else if(Accumulate_speed<-7000)Accumulate_speed=-7000;
    D_Error_speed = I_Error_speed - Last_Error_speed;
    Last_Error_speed = I_Error_speed;
    speed = proportion_speed*I_Error_speed + integral_speed*Accumulate_speed + differential_speed*D_Error_speed;
    
    speed = PID_Limit(speed , 9500);                       //��PID����޷�
    return (int)speed;
}

