/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		��ͫ����ͷ(SCC8660) RT FLEXIO�ӿ�
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598 & QQ2380006440)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.32.4 or MDK 5.24 �����
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-09-04
 * @note		
					���߶��壺
					------------------------------------ 
						ģ��ܽ�            ��Ƭ���ܽ�
						SDA(����ͷ��RX)     �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_COF_UART_TX�궨��
						SCL(����ͷ��TX)     �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_COF_UART_RX�궨��
                        ���ж�(VSY)         �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_VSYNC_PIN�궨��
						���ж�(HREF)		�鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_HREF_PIN�궨��
						�����ж�(PCLK)      �鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_PCLK_PIN�궨��
						���ݿ�(D0-D7)		�鿴SEEKFREE_SCC8660.h�ļ��е�SCC8660_DATA_PIN�궨��
					------------------------------------ 
	
					Ĭ�Ϸֱ���               160*120
					Ĭ��FPS                  20֡
 ********************************************************************************************************************/



#ifndef _SEEKFREE_SCC8660_h
#define _SEEKFREE_SCC8660_h


#include "common.h"
#include "zf_uart.h"




//����RT1021RAM���� �����Ҫ֧�ֵķֱ���Ϊ160*120 180*160

#define SCC8660_PIC_W           180		            //ʵ��ͼ��ֱ��ʿ��	��ѡ����Ϊ��160 180 240
#define SCC8660_PIC_H           160		            //ʵ��ͼ��ֱ��ʸ߶�	��ѡ����Ϊ��120 160 180

#define SCC8660_W		        SCC8660_PIC_W*2		//�˲���Ϊͼ�����ݴ洢��� �����޸�
#define SCC8660_H		        SCC8660_PIC_H       //�˲���Ϊͼ�����ݴ洢�߶� �����޸�

//--------------------------------------------------------------------------------------------------
//��������
//--------------------------------------------------------------------------------------------------
#define SCC8660_COF_UART        USART_3             //��������ͷ��ʹ�õ��Ĵ���     
#define SCC8660_COF_UART_TX     UART3_TX_C6
#define SCC8660_COF_UART_RX     UART3_RX_C7

#define SCC8660_VSYNC_PIN       B21                 //���ж�����
#define SCC8660_VSYNC_IRQN      GPIO1_Combined_16_31_IRQn   //�жϺ�
                                
                                
#define SCC8660_DATA_PIN        FLEXIO1_IO0_B31 //����D0��������  ����D0����ΪFLEXIO1_IO8_B23 ��ôD1��ʹ�õ�������ΪFLEXIO1_IO9_B22����������
#define SCC8660_PCLK_PIN        FLEXIO1_IO8_B23 //��������ʱ������
#define SCC8660_HREF_PIN        FLEXIO1_IO9_B22 //�������ź�����



typedef enum
{
    SCC8660_INIT 			= 0x00, //����ͷ��ʼ������
    SCC8660_AUTO_EXP,               //�Զ��ع�����
    SCC8660_BRIGHT,                 //��������
    SCC8660_FPS,                    //����ͷ֡������
    SCC8660_SET_COL,                //ͼ��������
    SCC8660_SET_ROW,                //ͼ��������
    SCC8660_PCLK_DIV,               //����ʱ�ӷ�Ƶ����
    SCC8660_PCLK_MODE,              //����ʱ��ģʽ����
    SCC8660_COLOR_MODE,             //ɫ��ģʽ����
    SCC8660_DATA_FORMAT,	        //���ݸ�ʽ����
	SCC8660_MANUAL_WB,	            //�ֶ���ƽ������
    SCC8660_CONFIG_FINISH,          //������λ����Ҫ����ռλ����
        
    SCC8660_GET_WHO_AM_I = 0xEF,    //����˭��������ж�����ͷ�ͺ�
    SCC8660_SET_BRIGHT = 0xF0,      //������������
    SCC8660_GET_STATUS 	= 0XF1,     //��ȡ����ͷ��������
    SCC8660_GET_VERSION	= 0xF2,     //�̼��汾��
	SCC8660_SET_MANUAL_WB = 0xF3,   //���������ֶ���ƽ��
        
    SCC8660_SET_REG_ADDR	= 0xFE, 
    SCC8660_SET_REG_DATA	= 0xFF, 
}SCC8660_CMD;



extern uint16 scc8660_image[SCC8660_PIC_H][SCC8660_PIC_W];
extern uint8  scc8660_finish_flag;                  //һ��ͼ��ɼ���ɱ�־λ



void    scc8660_set_all_config(UARTN_enum uartn, uint16 buff[SCC8660_CONFIG_FINISH-1][2]);
void    scc8660_get_all_config(UARTN_enum uartn, uint16 buff[SCC8660_CONFIG_FINISH-1][2]);
uint16  scc8660_get_id(UARTN_enum uartn);
uint16  scc8660_get_config(UARTN_enum uartn, uint8 config);
uint16  scc8660_get_version(UARTN_enum uartn);
uint16  scc8660_set_bright(UARTN_enum uartn, uint16 data);
uint16  scc8660_set_maunal_wb(UARTN_enum uartn, uint16 data);
uint16  scc8660_set_reg_addr(UARTN_enum uartn, uint8 reg, uint16 data);

void scc8660_init(void);
void scc8660_vsync(void);
void scc8660_dma(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);

void    seekfree_sendimg_scc8660(UARTN_enum uartn, uint8 *image, uint16 width, uint16 height);
void inline color_camera_take_point(uint16 *dat, uint16 x, uint16 y, uint16 z, uint8 *r, uint8 *g, uint8 *b);


#endif
