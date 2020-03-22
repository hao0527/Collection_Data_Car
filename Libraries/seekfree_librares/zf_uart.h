/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		uart
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
#ifndef _zf_uart_h
#define _zf_uart_h


#include "common.h"
#include "fsl_lpuart.h"

//��ö�ٶ��岻�����û��޸�
typedef enum //ö�ٴ�������
{
    UART1_TX_B6,
    UART1_RX_B7, 
    
    UART2_TX_B24,   UART2_TX_C22, 
    UART2_RX_B25,   UART2_RX_C23, 
    
    UART3_TX_B14,   UART3_TX_C6, 
    UART3_RX_B15,   UART3_RX_C7, 
        
    UART4_TX_B26,   UART4_TX_C2,    UART4_TX_D0, 
    UART4_RX_B27,   UART4_RX_C3,    UART4_RX_D1, 
        
    UART5_TX_B10,   UART5_TX_D6, 
    UART5_RX_B11,   UART5_RX_D7, 
        
    UART6_TX_C12,   UART6_TX_D20,
    UART6_RX_C13,   UART6_RX_D21,
    
    UART7_TX_D2,    UART7_TX_D17,
    UART7_RX_D3,    UART7_RX_D18,
                  
    UART8_TX_C26,   UART8_TX_D22,
    UART8_RX_C27,   UART8_RX_D23,
    
}UARTPIN_enum;


//��ö�ٶ��岻�����û��޸�
typedef enum //ö�ٴ��ں�
{
    USART_0,//RT1021û�д���0 ���������ռλ
    USART_1,
    USART_2,
    USART_3,
    USART_4,
    USART_5,
    USART_6,
    USART_7,
    USART_8,
}UARTN_enum;


void uart_init(UARTN_enum uartn, uint32 baud, UARTPIN_enum tx_pin, UARTPIN_enum rx_pin);
void uart_putchar(UARTN_enum uartn, uint8 dat);
void uart_putbuff(UARTN_enum uartn, uint8 *buff, uint32 len);
void uart_putstr(UARTN_enum uartn, const uint8 *str);
void uart_getchar(UARTN_enum uartn, uint8 *dat);
uint8 uart_query(UARTN_enum uartn, uint8 *dat);
void uart_tx_irq(UARTN_enum uartn,uint8 status);
void uart_rx_irq(UARTN_enum uartn,uint8 status);
void uart_set_handle(UARTN_enum uartn, lpuart_handle_t *handle, lpuart_transfer_callback_t callback, uint8 *tx_buff, uint32 tx_count, uint8 *rx_buff, uint32 rx_count);

#endif