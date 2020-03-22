#include "headfile.h"

void PIT_allocation_init()                  //�����жϷ�����   
{   
    pit_init();                             //���ڶ�ʱ��ģ���ʼ��
    
    pit_interrupt_ms(PIT_CH0,10);           //��ʼ��pitͨ��0 ����10ms
    pit_interrupt_ms(PIT_CH1,5);
    pit_interrupt_ms(PIT_CH2,3);
//    pit_interrupt_ms(PIT_CH3,500);
}

void PIT_IRQHandler(void)
{
    if(PIT_FLAG_GET(PIT_CH0))
    {
        PIT_FLAG_CLEAR(PIT_CH0);
        //�жϺ���
    }
    
    if(PIT_FLAG_GET(PIT_CH1))
    {
        PIT_FLAG_CLEAR(PIT_CH1);
        Get_ADC();                          //��ȡ���ֵ
        ADC_Compare();                      //����diff��Normalization
    }
    
    if(PIT_FLAG_GET(PIT_CH2))
    {
        PIT_FLAG_CLEAR(PIT_CH2);
        //�жϺ���
    }
    
//    if(PIT_FLAG_GET(PIT_CH3))
//    {
//        PIT_FLAG_CLEAR(PIT_CH3);
//        //�жϺ���
//    }
    
    __DSB();
}
