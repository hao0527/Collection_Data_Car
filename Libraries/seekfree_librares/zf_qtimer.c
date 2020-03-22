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
 

#include "zf_iomuxc.h"
#include "zf_qtimer.h"


#define QTMR_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_IpgClk)
#define QTIMER_PIN_CONF  SPEED_100MHZ | KEEPER_EN | DSE_R0_6 //����QTIMER����Ĭ������

TMR_Type * QTIMERN[] = TMR_BASE_PTRS;

void qtimer_iomuxc(QTIMERN_enum qtimern, QTIMER_PIN_enum phaseA, QTIMER_PIN_enum phaseB)
{
    switch(qtimern)
    {
        case QTIMER_1:
        {
            if((phaseA/2) == (phaseB/2))            assert(0);  //�������ô���,����������Ϊͬһ����ʱ�� ����ʧ��
            if      (QTIMER1_TIMER0_D0  == phaseA)  iomuxc_pinconf(D0 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER0_D13 == phaseA)  iomuxc_pinconf(D13,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER1_D1  == phaseA)  iomuxc_pinconf(D1 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER1_D14 == phaseA)  iomuxc_pinconf(D14,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER2_D2  == phaseA)  iomuxc_pinconf(D2 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER2_D15 == phaseA)  iomuxc_pinconf(D15,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER3_D3  == phaseA)  iomuxc_pinconf(D3 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER3_D16 == phaseA)  iomuxc_pinconf(D16,ALT1,QTIMER_PIN_CONF);
            else    assert(0);  //�������ô��� ����ʧ��
            
            if      (QTIMER1_TIMER0_D0  == phaseB)  iomuxc_pinconf(D0 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER0_D13 == phaseB)  iomuxc_pinconf(D13,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER1_D1  == phaseB)  iomuxc_pinconf(D1 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER1_D14 == phaseB)  iomuxc_pinconf(D14,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER2_D2  == phaseB)  iomuxc_pinconf(D2 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER2_D15 == phaseB)  iomuxc_pinconf(D15,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER3_D3  == phaseB)  iomuxc_pinconf(D3 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER1_TIMER3_D16 == phaseB)  iomuxc_pinconf(D16,ALT1,QTIMER_PIN_CONF);
            else    assert(0);  //�������ô��� ����ʧ��
            
        }break;
        case QTIMER_2:
        {
            if((phaseA/2) == (phaseB/2))            assert(0);  //�������ô���,����������Ϊͬһ����ʱ�� ����ʧ��
            if      (QTIMER2_TIMER0_B4  == phaseA)  iomuxc_pinconf(B4 ,ALT3,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER0_C0  == phaseA)  iomuxc_pinconf(C0 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER1_B5  == phaseA)  iomuxc_pinconf(B5 ,ALT3,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER1_C1  == phaseA)  iomuxc_pinconf(C1 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER2_B6  == phaseA)  iomuxc_pinconf(B6 ,ALT3,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER2_C2  == phaseA)  iomuxc_pinconf(C2 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER3_B7  == phaseA)  iomuxc_pinconf(B7 ,ALT3,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER3_C3  == phaseA)  iomuxc_pinconf(C3 ,ALT1,QTIMER_PIN_CONF);
            else    assert(0);  //�������ô��� ����ʧ��
            
            if      (QTIMER2_TIMER0_B4  == phaseB)  iomuxc_pinconf(B4 ,ALT3,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER0_C0  == phaseB)  iomuxc_pinconf(C0 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER1_B5  == phaseB)  iomuxc_pinconf(B5 ,ALT3,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER1_C1  == phaseB)  iomuxc_pinconf(C1 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER2_B6  == phaseB)  iomuxc_pinconf(B6 ,ALT3,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER2_C2  == phaseB)  iomuxc_pinconf(C2 ,ALT1,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER3_B7  == phaseB)  iomuxc_pinconf(B7 ,ALT3,QTIMER_PIN_CONF);
            else if (QTIMER2_TIMER3_C3  == phaseB)  iomuxc_pinconf(C3 ,ALT1,QTIMER_PIN_CONF);
            else    assert(0);  //�������ô��� ����ʧ��
        }break;
        default:assert(0);break;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      QTIMER���������ʼ��
//  @param      qtimern         ѡ��QTIMERģ��(QTIMER_1��QTIMER_2)
//  @param      phaseA          ѡ���������� A�˿�
//  @param      phaseB          ѡ���������� B�˿�
//  @return     void
//  Sample usage:				qtimer_quad_init(QTIMER_1, QTIMER1_TIMER0_D0, QTIMER1_TIMER1_D1);
//-------------------------------------------------------------------------------------------------------------------
void qtimer_quad_init(QTIMERN_enum qtimern, QTIMER_PIN_enum phaseA, QTIMER_PIN_enum phaseB)
{
    qtmr_config_t qtmrConfig;
    qtimer_iomuxc(qtimern, phaseA, phaseB);

    QTMR_GetDefaultConfig(&qtmrConfig);
    qtmrConfig.primarySource = (qtmr_primary_count_source_t)((phaseA&0x7)/2);
    qtmrConfig.secondarySource = (qtmr_input_source_t)((phaseB&0x7)/2);
    QTMR_Init(QTIMERN[qtimern], (qtmr_channel_selection_t)((phaseA&0x7)/2), &qtmrConfig);//��һ�γ�ʼ�����ڴ�ʱ��
    QTMR_Deinit(QTIMERN[qtimern], (qtmr_channel_selection_t)((phaseA&0x7)/2));           //��λ����
    QTMR_Init(QTIMERN[qtimern], (qtmr_channel_selection_t)((phaseA&0x7)/2), &qtmrConfig);//���³�ʼ��������ȷ�Ĳ���
    
    QTMR_StartTimer(QTIMERN[qtimern], (qtmr_channel_selection_t)((phaseA&0x7)/2), kQTMR_PriSrcRiseEdgeSecDir);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      QTIMER�������������ȡ
//  @param      qtimern         ѡ��QTIMERģ��(QTIMER_1��QTIMER_2)
//  @param      phaseA          ѡ���������� A�˿� ���������Ҫ��qtimer_quad_init�����ڶ�������һ�� 
//  @return     int16			���ز�������������
//  Sample usage:				qtimer_quad_get(QTIMER_1, QTIMER1_TIMER0_D0);//������Ҫע��
//-------------------------------------------------------------------------------------------------------------------
int16 qtimer_quad_get(QTIMERN_enum qtimern, QTIMER_PIN_enum phaseA)
{
    return QTMR_GetCurrentTimerCount(QTIMERN[qtimern], (qtmr_channel_selection_t)((phaseA&0x7)/2));
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      QTIMER���������������
//  @param      qtimern         ѡ��QTIMERģ��(QTIMER_1��QTIMER_2)
//  @param      phaseA          ѡ���������� A�˿� ���������Ҫ��qtimer_quad_init�����ڶ�������һ�� 
//  @return     void
//  Sample usage:				qtimer_quad_clear(QTIMER_1, QTIMER1_TIMER0_D0);
//-------------------------------------------------------------------------------------------------------------------
void qtimer_quad_clear(QTIMERN_enum qtimern, QTIMER_PIN_enum phaseA)
{
    QTIMERN[qtimern]->CHANNEL[(phaseA&0x7)/2].CNTR = 0;
}

