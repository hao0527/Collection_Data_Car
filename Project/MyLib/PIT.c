#include "headfile.h"

void PIT_allocation_init()                  //�����жϷ�����   
{   
    pit_init();                             //���ڶ�ʱ��ģ���ʼ��
    
    pit_interrupt_ms(PIT_CH0,10);           //��ʼ��pitͨ��0 ����10ms
    pit_interrupt_ms(PIT_CH1,5);
    pit_interrupt_ms(PIT_CH2,20);
//    pit_interrupt_ms(PIT_CH3,500);
}

void PIT_IRQHandler(void)
{
    if(PIT_FLAG_GET(PIT_CH0))
    {
        PIT_FLAG_CLEAR(PIT_CH0);
        PUTOUT_PWM();                       //���PWM��
    }
    
    if(PIT_FLAG_GET(PIT_CH1))
    {
        PIT_FLAG_CLEAR(PIT_CH1);
        Get_ADC();                          //��ȡ���ֵ
        ADC_Compare();                      //����diff��Normalization
        Get_Speed();                        //��ȡ������
        GET_PWM();                          //�����㷨����PWM
    }
    
    if(PIT_FLAG_GET(PIT_CH2))
    {
        PIT_FLAG_CLEAR(PIT_CH2);
        KeyScan();                          //������ֵ
//        if(B1==0&&B2==0&&B4==1&&B4==1) OLED_Flag=0;
//        if(B1==0&&B2==1&&B4==1&&B4==1) OLED_Flag=1;
//        if(B1==1&&B2==0&&B4==1&&B4==1) 
//        {
//            OLED_Flag=2;
//            if(S4==1) Get_Basis_DG();       //�õ���Ŵ��������� �����ó�ʼֵ
//            if(S1==1) Clean_Basis_DG();     //���Basis
//        }
//        if(B1==1&&B2==1&&B4==1&&B4==1) 
//        {
//            OLED_Flag=3;
//            if(S4==1) Save_DuoJi_Flash();
//            if(S3==1) {DuoJi_Mid=flash_read(108,0,uint16);if(DuoJi_Mid<DuoJi_Left) DuoJi_Mid=DuoJi_Left;if(DuoJi_Mid>DuoJi_Right) DuoJi_Mid=DuoJi_Right;}
//            if(S1==1) {DuoJi_Mid-=1;if(DuoJi_Mid<DuoJi_Left) DuoJi_Mid=DuoJi_Left;if(DuoJi_Mid>DuoJi_Right) DuoJi_Mid=DuoJi_Right;}
//            if(S2==1) {DuoJi_Mid+=1;if(DuoJi_Mid<DuoJi_Left) DuoJi_Mid=DuoJi_Left;if(DuoJi_Mid>DuoJi_Right) DuoJi_Mid=DuoJi_Right;}
//        }
//        if(B1==0&&B2==0&&B4==0&&B4==0) OLED_Flag=4;
    }
    
//    if(PIT_FLAG_GET(PIT_CH3))
//    {
//        PIT_FLAG_CLEAR(PIT_CH3);
//        //�жϺ���
//    }
    
    __DSB();
}
