/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		pwm
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
#ifndef _zf_pwm_h
#define _zf_pwm_h

#include "common.h"
#include "fsl_pwm.h"

//��ö�ٶ��岻�����û��޸�
typedef enum
{
    PWM1_MODULE0_CHB_B23=16,PWM1_MODULE0_CHB_C27,//PWM1 ��ģ��0 ͨ��B  ���ſ�ѡ��Χ
    PWM1_MODULE0_CHA_B22,   PWM1_MODULE0_CHA_C26,//PWM1 ��ģ��0 ͨ��A  ���ſ�ѡ��Χ ͬһ����ģ�鲻ͬͨ��ֻ�������ͬƵ�ʵ�PWM��ռ�ձȿ����ò�ͬ
    
    PWM1_MODULE1_CHB_B25,   PWM1_MODULE1_CHB_C25,//PWM1 ��ģ��1 ͨ��B  ���ſ�ѡ��Χ
    PWM1_MODULE1_CHA_B24,   PWM1_MODULE1_CHA_C24,//PWM1 ��ģ��1 ͨ��A  ���ſ�ѡ��Χ
    
    PWM1_MODULE2_CHB_B27,   PWM1_MODULE2_CHB_C23,//PWM1 ��ģ��2 ͨ��B  ���ſ�ѡ��Χ
    PWM1_MODULE2_CHA_B26,   PWM1_MODULE2_CHA_C22,//PWM1 ��ģ��2 ͨ��A  ���ſ�ѡ��Χ

    PWM1_MODULE3_CHB_B29,   PWM1_MODULE3_CHB_C21,//PWM1 ��ģ��3 ͨ��B  ���ſ�ѡ��Χ
    PWM1_MODULE3_CHA_B28,   PWM1_MODULE3_CHA_C20,//PWM1 ��ģ��3 ͨ��A  ���ſ�ѡ��Χ
    
    //-----------------------------------------------------------------------------
    PWM2_MODULE0_CHB_B15,   PWM2_MODULE0_CHB_D7, //PWM2 ��ģ��0 ͨ��B  ���ſ�ѡ��Χ
    PWM2_MODULE0_CHA_B14,   PWM2_MODULE0_CHA_D6, //PWM2 ��ģ��0 ͨ��A  ���ſ�ѡ��Χ

    PWM2_MODULE1_CHB_B13,   PWM2_MODULE1_CHB_D5, //PWM2 ��ģ��1 ͨ��B  ���ſ�ѡ��Χ
    PWM2_MODULE1_CHA_B12,   PWM2_MODULE1_CHA_D4, //PWM2 ��ģ��1 ͨ��A  ���ſ�ѡ��Χ

    PWM2_MODULE2_CHB_B11,   PWM2_MODULE2_CHB_C31,//PWM2 ��ģ��2 ͨ��B  ���ſ�ѡ��Χ
    PWM2_MODULE2_CHA_B10,   PWM2_MODULE2_CHA_C30,//PWM2 ��ģ��2 ͨ��A  ���ſ�ѡ��Χ

    PWM2_MODULE3_CHB_B7,    PWM2_MODULE3_CHB_C29,//PWM2 ��ģ��3 ͨ��B  ���ſ�ѡ��Χ
    PWM2_MODULE3_CHA_B6,    PWM2_MODULE3_CHA_C28,//PWM2 ��ģ��3 ͨ��A  ���ſ�ѡ��Χ
    
}PWMCH_enum;




void pwm_init(PWMCH_enum pwmch, uint32 freq, uint32 duty);
void pwm_duty(PWMCH_enum pwmch, uint32 duty);
void pwm_freq(PWMCH_enum pwmch, uint32 freq, uint32 duty);



#endif