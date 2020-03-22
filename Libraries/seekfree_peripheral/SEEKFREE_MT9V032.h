/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		�����
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 * @note		
					���߶��壺
					------------------------------------ 
						ģ��ܽ�            ��Ƭ���ܽ�
						SDA(51��RX)         C6
						SCL(51��TX)         C7
						���ж�(VSY)         B21
						���ж�(HREF)		B22
						�����ж�(PCLK)      B23
						���ݿ�(D0-D7)		B31-B24 B31��Ӧ����ͷ�ӿ�D0
					------------------------------------ 
	
					Ĭ�Ϸֱ�����            188*120
					Ĭ��FPS                 50֡
 ********************************************************************************************************************/



#ifndef _SEEKFREE_MT9V032_h
#define _SEEKFREE_MT9V032_h

#include "common.h"
#include "zf_uart.h"

//��������ͷ����
#define MT9V032_DMA_CH          DMA_CH0         //��������ͷ��DMA�ɼ�ͨ��
#define MT9V032_W               188             //ͼ����  ��Χ1-752       RT102X RT105X RT106X �ɼ�ʱ�п�ȱ���Ϊ4�ı���
#define MT9V032_H               120             //ͼ��߶�	��Χ1-480



//--------------------------------------------------------------------------------------------------
//��������
//--------------------------------------------------------------------------------------------------
#define MT9V032_COF_UART        USART_3         //��������ͷ��ʹ�õ��Ĵ���     
#define MT9V032_COF_UART_TX     UART3_TX_C6
#define MT9V032_COF_UART_RX     UART3_RX_C7

#define MT9V032_VSYNC_PIN       B21             //���ж�����
#define MT9V032_VSYNC_IRQN      GPIO1_Combined_16_31_IRQn   //�жϺ�


#define MT9V032_DATA_PIN        FLEXIO1_IO0_B31 //����D0��������  ����D0����ΪFLEXIO1_IO8_B23 ��ôD1��ʹ�õ�������ΪFLEXIO1_IO9_B22����������
#define MT9V032_PCLK_PIN        FLEXIO1_IO8_B23 //��������ʱ������
#define MT9V032_HREF_PIN        FLEXIO1_IO9_B22 //�������ź�����

             
                        
//����ͷ����ö��
typedef enum
{
    INIT = 0,               //����ͷ��ʼ������
    AUTO_EXP,               //�Զ��ع�����
    EXP_TIME,               //�ع�ʱ������
    FPS,                    //����ͷ֡������
    SET_COL,                //ͼ��������
    SET_ROW,                //ͼ��������
    LR_OFFSET,              //ͼ������ƫ������
    UD_OFFSET,              //ͼ������ƫ������
    GAIN,                   //ͼ��ƫ������
    CONFIG_FINISH,          //������λ����Ҫ����ռλ����
    
    SET_EXP_TIME = 0XF0,    //���������ع�ʱ������
    GET_STATUS,             //��ȡ����ͷ��������
    GET_VERSION,            //�̼��汾������
	
    SET_ADDR = 0XFE,        //�Ĵ�����ַ����
    SET_DATA                //�Ĵ�����������
}CMD;
     
     
     
                            
                            

extern uint8 mt9v032_finish_flag;  //һ��ͼ��ɼ���ɱ�־λ
extern uint8 image[MT9V032_H][MT9V032_W];      //�ڲ�ʹ��
                            
                            
void camera_init(void);
void mt9v032_vsync(void);
void mt9v032_dma(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);
void seekfree_sendimg_032(UARTN_enum uartn);




#endif

