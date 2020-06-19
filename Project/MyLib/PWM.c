#include "headfile.h"

//����2.5m˫������ٿ��Ʋ���Ҫ

int PID, PWM_DianJi_L, PWM_DianJi_R;                //ȫ�ֱ���
int PWM_DuoJi=3722, DuoJi_Mid=3722;                      //ȫ�ֱ���
int DuoJi_Left=4005, DuoJi_Right=3245;              //ȫ�ֱ���
int car_mode;                                       //ȫ�ֱ���  ����ģʽ��0Ϊ�Զ���1λ�ֶ�
int LQ,LH,RQ,RH;

int PWM_Limit(int value,int limit)                  //��value�޷��ڣ�1��limit����Χ
{
    value = value > limit ?  limit : value;
    value = value < 1 ? 1 : value;
    return (int)value;
}

int DuoJi_PWM_Limit(int value)                      //��value�޷��ڣ�2417��3817����Χ
{
    if(value>DuoJi_Right) value=DuoJi_Right;
    if(value<DuoJi_Left) value=DuoJi_Left;
    return (int)value;
}

void PWM_allocation_init()                          //����PWM����ܽ�
{
    pwm_init(PWM2_MODULE3_CHA_C28, 15000, 0);       //�����Ƶ�ʸ�15kHz�����ռ�ձ�Ĭ��Ϊ50000
    pwm_init(PWM2_MODULE2_CHB_C31, 15000, 0);
    pwm_init(PWM2_MODULE3_CHB_C29, 15000, 0);
    pwm_init(PWM2_MODULE2_CHA_C30, 15000, 0);
    pwm_init(PWM1_MODULE0_CHB_C27, 50, 0);         //���
}  

void PUTOUT_PWM()                                   //���PWM��
{
    pwm_duty(PWM2_MODULE3_CHA_C28, LQ);   //���
    pwm_duty(PWM2_MODULE3_CHB_C29, LH);
    pwm_duty(PWM2_MODULE2_CHB_C31, RQ);
    pwm_duty(PWM2_MODULE2_CHA_C30, LH);
    pwm_duty(PWM1_MODULE0_CHB_C27, PWM_DuoJi);      //���
}

void GET_DuoJi_PWM()                                //��ʱ������������������ȡTurn_Flag
{   
//    if((XL1>=(0.094F*Basis_XL1))&&(XR1>=(0.211f*Basis_XR1))) Turn_Flag=3;
//    if((XL1>=(0.203F*Basis_XL1))&&(XR1>=(0.368f*Basis_XR1))) Turn_Flag=2;
//    if((XL1>=(0.406F*Basis_XL1))&&(XR1>=(0.509f*Basis_XR1))) Turn_Flag=1;
//    if((XL1>=(0.500F*Basis_XL1))&&(XR1>=(0.570f*Basis_XR1))) Turn_Flag=0;
//    if((XL1<=(0.094F*Basis_XL1))||(XR1<=(0.211f*Basis_XR1))) Turn_Flag=4;
//    
//    switch (Turn_Flag)
//    {
//    case 0:{Speed_Flag=0;PID=Pid_Count_0(0,1,0,0,NormalizationX1);PID_Limit(PID,100);PWM_DuoJi=PID+DuoJi_Mid;break;}
//    case 1:{Speed_Flag=1;PID=Pid_Count_0(0,2,0,0,NormalizationX1);PID_Limit(PID,250);PWM_DuoJi=PID+DuoJi_Mid;break;}
//    case 2:{Speed_Flag=2;PID=Pid_Count_0(0,3,0,0,NormalizationX1);PID_Limit(PID,400);PWM_DuoJi=PID+DuoJi_Mid;break;}
//    case 3:{Speed_Flag=3;PID=Pid_Count_1(0,4,0,0,NormalizationX1);PID_Limit(PID,550);PWM_DuoJi=PID+DuoJi_Mid;break;}
//    case 4:{Speed_Flag=4;PID=Pid_Count_1(0,5,0,0,NormalizationX1);PID_Limit(PID,700);PWM_DuoJi=PID+DuoJi_Mid;break;}
//    }
}

void GET_PWM()
{
    if(car_mode==0)
    {
    
    }
    else
    {
        PWM_DuoJi=DuoJi_Mid-vx*3.0;
        PWM_DianJi_L=vy*150;
        PWM_DianJi_R=vy*150;
        if(PWM_DianJi_L>=0) {LQ=PWM_DianJi_L;LH=0;}
        else {LH=-PWM_DianJi_L;LQ=0;}
        if(PWM_DianJi_R>=0) {RQ=PWM_DianJi_R;RH=0;}
        else {RH=-PWM_DianJi_R;RQ=0;}
    }
//    if(OLED_Flag!=3)
//    {
//        GET_DuoJi_PWM();
//    }
//    else
//        PWM_DuoJi=DuoJi_Mid;                //���������
    
//    GET_DuoJi_PWM();                        //���������ע�͵��ˣ��������
//    PWM_DuoJi = DuoJi_PWM_Limit(PWM_DuoJi);
    
//    PWM_DianJi_L = Pid_Count_SPEED(Get_Speed_aim(Speed_Flag),8,9,10,SPEED_DianJi);
//    PWM_DianJi_R = Pid_Count_SPEED(Get_Speed_aim(Speed_Flag),8,9,10,SPEED_DianJi);
//    PWM_DianJi = PWM_Limit(PWM_DianJi,8000);
}




