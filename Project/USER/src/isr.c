/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		isr
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/

#include "headfile.h"
#include "isr.h"




//uint32 te;
//void PIT_IRQHandler(void)
//{
//    if(PIT_FLAG_GET(PIT_CH0))
//    {
//        PIT_FLAG_CLEAR(PIT_CH0);
//        gpio_toggle(C14);
//    }
//    
//    if(PIT_FLAG_GET(PIT_CH1))
//    {
//        PIT_FLAG_CLEAR(PIT_CH1);
//        gpio_toggle(C15);
//    }
//    
//    if(PIT_FLAG_GET(PIT_CH2))
//    {
//        PIT_FLAG_CLEAR(PIT_CH2);
//        gpio_toggle(D5);
//    }
//    
//    if(PIT_FLAG_GET(PIT_CH3))
//    {
//        PIT_FLAG_CLEAR(PIT_CH3);
//        gpio_toggle(D7);
//    }

//    __DSB();
//}


//void GPIO1_Combined_16_31_IRQHandler(void)
//{
//    mt9v032_vsync();
//    
//}






/*
�жϺ������ƣ��������ö�Ӧ���ܵ��жϺ���
Sample usage:��ǰ���������ڶ�ʱ���ж�
void PIT_IRQHandler(void)
{
    //��������־λ
    __DSB();
}
�ǵý����жϺ������־λ
CTI0_ERROR_IRQHandler
CTI1_ERROR_IRQHandler
CORE_IRQHandler
FLEXRAM_IRQHandler
KPP_IRQHandler
Reserved56_IRQHandler
GPR_IRQ_IRQHandler
Reserved58_IRQHandler
Reserved59_IRQHandler
Reserved60_IRQHandler
WDOG2_IRQHandler
SNVS_HP_WRAPPER_IRQHandler
SNVS_HP_WRAPPER_TZ_IRQHandler
SNVS_LP_WRAPPER_IRQHandler
CSU_IRQHandler
DCP_IRQHandler
DCP_VMI_IRQHandler
Reserved68_IRQHandler
TRNG_IRQHandler
Reserved70_IRQHandler
BEE_IRQHandler
PMU_IRQHandler
Reserved78_IRQHandler
TEMP_LOW_HIGH_IRQHandler
TEMP_PANIC_IRQHandler
USB_PHY_IRQHandler
Reserved82_IRQHandler
ADC1_IRQHandler
ADC2_IRQHandler
DCDC_IRQHandler
Reserved86_IRQHandler
Reserved87_IRQHandler
GPIO1_INT0_IRQHandler
GPIO1_INT1_IRQHandler
GPIO1_INT2_IRQHandler
GPIO1_INT3_IRQHandler
GPIO1_INT4_IRQHandler
GPIO1_INT5_IRQHandler
GPIO1_INT6_IRQHandler
GPIO1_INT7_IRQHandler
GPIO1_Combined_0_15_IRQHandler
GPIO1_Combined_16_31_IRQHandler
GPIO2_Combined_0_15_IRQHandler
GPIO2_Combined_16_31_IRQHandler
GPIO3_Combined_0_15_IRQHandler
GPIO3_Combined_16_31_IRQHandler
Reserved102_IRQHandler
Reserved103_IRQHandler
GPIO5_Combined_0_15_IRQHandler
GPIO5_Combined_16_31_IRQHandler
Reserved107_IRQHandler
WDOG1_IRQHandler
RTWDOG_IRQHandler
EWM_IRQHandler
CCM_1_IRQHandler
CCM_2_IRQHandler
GPC_IRQHandler
SRC_IRQHandler
Reserved115_IRQHandler
GPT1_IRQHandler
GPT2_IRQHandler
PWM1_0_IRQHandler
PWM1_1_IRQHandler
PWM1_2_IRQHandler
PWM1_3_IRQHandler
PWM1_FAULT_IRQHandler
Reserved123_IRQHandler
SEMC_IRQHandler
Reserved128_IRQHandler
USB_OTG1_IRQHandler
XBAR1_IRQ_0_1_IRQHandler
XBAR1_IRQ_2_3_IRQHandler
ADC_ETC_IRQ0_IRQHandler
ADC_ETC_IRQ1_IRQHandler
ADC_ETC_IRQ2_IRQHandler
ADC_ETC_ERROR_IRQ_IRQHandler
PIT_IRQHandler
ACMP1_IRQHandler
ACMP2_IRQHandler
ACMP3_IRQHandler
ACMP4_IRQHandler
Reserved143_IRQHandler
Reserved144_IRQHandler
ENC1_IRQHandler
ENC2_IRQHandler
Reserved147_IRQHandler
Reserved148_IRQHandler
TMR1_IRQHandler
TMR2_IRQHandler
Reserved151_IRQHandler
Reserved152_IRQHandler
PWM2_0_IRQHandler
PWM2_1_IRQHandler
PWM2_2_IRQHandler
PWM2_3_IRQHandler
PWM2_FAULT_IRQHandler*/



