/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		adc
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
#ifndef _zf_adc_h
#define _zf_adc_h


#include "common.h"
#include "fsl_adc.h"



//��ö�ٶ��岻�����û��޸�
typedef enum    // ö��ADCͨ��
{
    ADC1_CH0_B12,    
    ADC1_CH1_B14,    
    ADC1_CH2_B15,    
    ADC1_CH3_B17,    
    ADC1_CH4_B19,    
    ADC1_CH5_B21,    
    ADC1_CH6_B22,    
    ADC1_CH7_B23,        
    ADC1_CH8_B24,        
    ADC1_CH9_B25,        
    ADC1_CH10_B26,       
    ADC1_CH11_B27,
    ADC1_CH12_B28,
    ADC1_CH13_B29,
    ADC1_CH14_B30,
    ADC1_CH15_B31,
    
    ADC2_CH0_B13,    
    ADC2_CH1_B14,    
    ADC2_CH2_B15,    
    ADC2_CH3_B18,    
    ADC2_CH4_B20,    
    ADC2_CH5_B21,    
    ADC2_CH6_B22,    
    ADC2_CH7_B23,        
    ADC2_CH8_B24,        
    ADC2_CH9_B25,        
    ADC2_CH10_B26,       
    ADC2_CH11_B27,
    ADC2_CH12_B28,
    ADC2_CH13_B29,
    ADC2_CH14_B30,
    ADC2_CH15_B31,
}ADCCH_enum;

//��ö�ٶ��岻�����û��޸�
typedef enum    // ö��ADCͨ��
{
    ADC_8BIT,     //8λ�ֱ���
    ADC_10BIT,    //10λ�ֱ���
    ADC_12BIT,    //12λ�ֱ���

}ADCRES_enum;

//��ö�ٶ��岻�����û��޸�
typedef enum    // ö��ADC���
{
    ADC_0,      //RT1021û��ADC0 ���������ռλ
    ADC_1,     
    ADC_2,  

}ADCN_enum;





void adc_init(ADCN_enum adcn, ADCCH_enum ch, ADCRES_enum resolution);
uint16 adc_convert(ADCN_enum adcn, ADCCH_enum ch);
uint16 adc_mean_filter(ADCN_enum adcn, ADCCH_enum ch, uint8 count);





#endif