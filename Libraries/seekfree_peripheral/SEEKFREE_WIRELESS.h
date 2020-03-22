/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		��ɿƼ�����ת����ģ��
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-03-27
 * @note		    
 ********************************************************************************************************************/

#ifndef _SEEKFREE_WIRELESS
#define _SEEKFREE_WIRELESS


#include "common.h"


#define WIRELESS_UART        USART_7         //����ת����ģ�� ��ʹ�õ��Ĵ���     
#define WIRELESS_UART_TX     UART7_TX_D17
#define WIRELESS_UART_RX     UART7_RX_D18
#define WIRELESS_UART_BAUD   115200

#define RTS_PIN D16 //��������λ����  ָʾ��ǰģ���Ƿ���Խ�������  0���Լ�������  1�����Լ�������
#define CMD_PIN D19 //������������



void    seekfree_wireless_init(void);
uint32  seekfree_wireless_send_buff(uint8 *buff, uint32 len);

#endif 
