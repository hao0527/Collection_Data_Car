#include "headfile.h"


void PIT_allocation_init() 					//�����жϷ�����   
{   
	pit_init();								//���ڶ�ʱ��ģ���ʼ��
	pit_interrupt_ms(PIT_CH0,100);  //��ʼ��pitͨ��0 ����
    pit_interrupt_ms(PIT_CH1,300);  //��ʼ��pitͨ��1 ����
    pit_interrupt_ms(PIT_CH2,600);  //��ʼ��pitͨ��2 ����
    pit_interrupt_ms(PIT_CH3,900);  //��ʼ��pitͨ��3 ����
	






    pit_init_ms(PIT0, 10);
    set_vector_handler(PIT0_VECTORn , PIT0_IRQHandler);   //����LPTMR���жϷ�����Ϊ PORTA_IRQHandler
    enable_irq(PIT0_IRQn);    
    
    pit_init_ms(PIT1, 5);
    set_vector_handler(PIT1_VECTORn , PIT1_IRQHandler);   //����LPTMR���жϷ�����Ϊ PORTA_IRQHandler
    enable_irq(PIT1_IRQn);    
    
    pit_init_ms(PIT2, 3);
    set_vector_handler(PIT2_VECTORn , PIT2_IRQHandler);   //����LPTMR���жϷ�����Ϊ PORTA_IRQHandler
    enable_irq(PIT2_IRQn);    
    
    NVIC_SetPriorityGrouping(4);     //�������ȼ�����,4bit ��ռ���ȼ�,û�������ȼ�
    NVIC_SetPriority(PIT0_IRQn,2);  
    NVIC_SetPriority(PIT1_IRQn,1); 
    NVIC_SetPriority(PIT2_IRQn,0); 
    
}  

void PIT0_IRQHandler()
{
/*
    if((GYH_AD[0] ==1)&&(GYH_AD[1] ==1)&&(GYH_AD[2] ==1)&&(GYH_AD[3] ==1))   //���жϱ�־λsi[i]       
    {
        PIT_Flag_Clear(PIT0);
        return;
    }
*/
  
    //��ʱ���жϷ������д������
    led_turn(LED0);

    Get_Speed();                //��ȡ������ֵ
    PUTOUT_PWM();               //���PWM��
    
    PIT_Flag_Clear(PIT0);       //���жϱ�־λsi[i]

}


void PIT1_IRQHandler()
{
  
    //��ʱ���жϷ������д������
    led_turn(LED1);

    Get_ADC();                  //��ȡ���ֵ
    ADC_Compare();              //����diff��Normalization
    GET_PWM();                  //ͨ�������㷨�õ�PWMֵ
    
    PIT_Flag_Clear(PIT1);       //���жϱ�־λsi[i]

}


void PIT2_IRQHandler()
{
    //��ʱ���жϷ������д������
    led_turn(LED2);

    KeyScan();                  //������ֵ
    if(S4==1) Get_Basis_DG();   //�õ���Ŵ��������� �����ó�ʼֵ

    PIT_Flag_Clear(PIT2);       //���жϱ�־λsi[i]

}


