/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		qtimer
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
#ifndef _zf_qtimer_h
#define _zf_qtimer_h



#include "common.h"
#include "fsl_qtmr.h"

//��ö�ٶ��岻�����û��޸�
typedef enum    //QTIMER����ö��
{
    QTIMER1_TIMER0_D0,QTIMER1_TIMER0_D13, //��ʱ��0 ͬһʱ��ֻ����һ�������붨ʱ�������
    QTIMER1_TIMER1_D1,QTIMER1_TIMER1_D14, //��ʱ��1 ͬһʱ��ֻ����һ�������붨ʱ������� 
    QTIMER1_TIMER2_D2,QTIMER1_TIMER2_D15, //��ʱ��2 ͬһʱ��ֻ����һ�������붨ʱ������� 
    QTIMER1_TIMER3_D3,QTIMER1_TIMER3_D16, //��ʱ��3 ͬһʱ��ֻ����һ�������붨ʱ������� 
    
    QTIMER2_TIMER0_B4,QTIMER2_TIMER0_C0, //��ʱ��0 ͬһʱ��ֻ����һ�������붨ʱ�������  
    QTIMER2_TIMER1_B5,QTIMER2_TIMER1_C1, //��ʱ��1 ͬһʱ��ֻ����һ�������붨ʱ������� 
    QTIMER2_TIMER2_B6,QTIMER2_TIMER2_C2, //��ʱ��2 ͬһʱ��ֻ����һ�������붨ʱ������� 
    QTIMER2_TIMER3_B7,QTIMER2_TIMER3_C3, //��ʱ��3 ͬһʱ��ֻ����һ�������붨ʱ������� 
    
}QTIMER_PIN_enum;

//��ö�ٶ��岻�����û��޸�
typedef enum    //QTIMER���ö��
{
    QTIMER_0,//RT1021û��QTIMER0 ���������ռλ
    QTIMER_1,
    QTIMER_2,
}QTIMERN_enum;


void qtimer_quad_init(QTIMERN_enum qtimern, QTIMER_PIN_enum phaseA, QTIMER_PIN_enum phaseB);
int16 qtimer_quad_get(QTIMERN_enum qtimern, QTIMER_PIN_enum phaseA);
void qtimer_quad_clear(QTIMERN_enum qtimern, QTIMER_PIN_enum phaseA);

#endif
 
