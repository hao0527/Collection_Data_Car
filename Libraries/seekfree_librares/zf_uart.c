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
 
 
 

#include "zf_iomuxc.h"
#include "board.h"
#include "zf_uart.h"

LPUART_Type * UARTN[] = LPUART_BASE_PTRS;

#define LPUART_PIN_CONF SPEED_100MHZ | KEEPER_EN | DSE_R0_6 //����UART����Ĭ������

void uart_iomuxc(UARTN_enum uartn, UARTPIN_enum tx_pin, UARTPIN_enum rx_pin)
{
    switch(uartn)
    {
        case USART_1:
        {
            if      (UART1_TX_B6 == tx_pin)     iomuxc_pinconf(B6 ,ALT2,LPUART_PIN_CONF); 
            if      (UART1_RX_B7 == rx_pin)     iomuxc_pinconf(B7 ,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_2:
        {
            if      (UART2_TX_B24 == tx_pin)    iomuxc_pinconf(B24,ALT2,LPUART_PIN_CONF); 
            else if (UART2_TX_C22 == tx_pin)    iomuxc_pinconf(C22,ALT2,LPUART_PIN_CONF); 
            
            if      (UART2_RX_B25 == rx_pin)    iomuxc_pinconf(B25,ALT2,LPUART_PIN_CONF); 
            else if (UART2_RX_C23 == rx_pin)    iomuxc_pinconf(C23,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_3:
        {
            if      (UART3_TX_B14 == tx_pin)    iomuxc_pinconf(B14,ALT2,LPUART_PIN_CONF); 
            else if (UART3_TX_C6  == tx_pin)    iomuxc_pinconf(C6 ,ALT2,LPUART_PIN_CONF); 
                                                               
            if      (UART3_RX_B15 == rx_pin)    iomuxc_pinconf(B15,ALT2,LPUART_PIN_CONF); 
            else if (UART3_RX_C7  == rx_pin)    iomuxc_pinconf(C7 ,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_4:
        {
            if      (UART4_TX_B26 == tx_pin)    iomuxc_pinconf(B26,ALT2,LPUART_PIN_CONF); 
            else if (UART4_TX_C2  == tx_pin)    iomuxc_pinconf(C2 ,ALT2,LPUART_PIN_CONF); 
            else if (UART4_TX_D0  == tx_pin)    iomuxc_pinconf(D0 ,ALT2,LPUART_PIN_CONF); 
                                                                  
            if      (UART4_RX_B27 == rx_pin)    iomuxc_pinconf(B27,ALT2,LPUART_PIN_CONF); 
            else if (UART4_RX_C3  == rx_pin)    iomuxc_pinconf(C3 ,ALT2,LPUART_PIN_CONF); 
            else if (UART4_RX_D1  == rx_pin)    iomuxc_pinconf(D1 ,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_5:
        {
            if      (UART5_TX_B10 == tx_pin)    iomuxc_pinconf(B10,ALT2,LPUART_PIN_CONF); 
            else if (UART5_TX_D6  == tx_pin)    iomuxc_pinconf(D6 ,ALT2,LPUART_PIN_CONF); 
                                                                  
            if      (UART5_RX_B11 == rx_pin)    iomuxc_pinconf(B11,ALT2,LPUART_PIN_CONF); 
            else if (UART5_RX_D7  == rx_pin)    iomuxc_pinconf(D7 ,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_6:
        {
            if      (UART6_TX_C12 == tx_pin)    iomuxc_pinconf(C12,ALT2,LPUART_PIN_CONF); 
            else if (UART6_TX_D20 == tx_pin)    iomuxc_pinconf(D20,ALT2,LPUART_PIN_CONF); 
                                                                  
            if      (UART6_RX_C13 == rx_pin)    iomuxc_pinconf(C13,ALT2,LPUART_PIN_CONF); 
            else if (UART6_RX_D21 == rx_pin)    iomuxc_pinconf(D21,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_7:
        {
            if      (UART7_TX_D2  == tx_pin)    iomuxc_pinconf(D2 ,ALT2,LPUART_PIN_CONF); 
            else if (UART7_TX_D17 == tx_pin)    iomuxc_pinconf(D17,ALT2,LPUART_PIN_CONF); 
                                                                  
            if      (UART7_RX_D3  == rx_pin)    iomuxc_pinconf(D3 ,ALT2,LPUART_PIN_CONF); 
            else if (UART7_RX_D18 == rx_pin)    iomuxc_pinconf(D18,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_8:
        {
            if      (UART8_TX_C26 == tx_pin)    iomuxc_pinconf(C26,ALT2,LPUART_PIN_CONF); 
            else if (UART8_TX_D22 == tx_pin)    iomuxc_pinconf(D22,ALT2,LPUART_PIN_CONF); 
                                                                  
            if      (UART8_RX_C27 == rx_pin)    iomuxc_pinconf(C27,ALT2,LPUART_PIN_CONF); 
            else if (UART8_RX_D23 == rx_pin)    iomuxc_pinconf(D23,ALT2,LPUART_PIN_CONF); 
        }break;
        
        default: assert(0);break;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ���ڳ�ʼ��
//  @param      uartn           ����ģ���(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      baud            ���ڲ�����
//  @param      tx_pin          ���ڷ�������
//  @param      rx_pin          ���ڽ�������
//  @return     uint32          ʵ�ʲ�����
//  Sample usage:               uart_init(USART_0,115200,UART0_TX_A25,UART0_RX_A24);       // ��ʼ������0 ������115200 ��������ʹ��P025 ��������ʹ��P024
//-------------------------------------------------------------------------------------------------------------------
void uart_init(UARTN_enum uartn, uint32 baud, UARTPIN_enum tx_pin, UARTPIN_enum rx_pin)
{
    uint32_t uartClkSrcFreq;
    lpuart_config_t lpuartConfig;
    
    uart_iomuxc(uartn,tx_pin,rx_pin);
    uartClkSrcFreq = BOARD_DebugConsoleSrcFreq();
    LPUART_GetDefaultConfig(&lpuartConfig);
    lpuartConfig.baudRate_Bps = baud;
    lpuartConfig.enableTx = true;
    lpuartConfig.enableRx = true;
    
    LPUART_Init(UARTN[uartn],&lpuartConfig,uartClkSrcFreq); //��һ�γ�ʼ�����ڴ�ʱ��
    LPUART_Deinit(UARTN[uartn]);                            //��λ����
    LPUART_Init(UARTN[uartn],&lpuartConfig,uartClkSrcFreq); //���³�ʼ��������ȷ�Ĳ���
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �����ֽ����
//  @param      uartn           ����ģ���(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      dat             ��Ҫ���͵��ֽ�
//  @return     void        
//  Sample usage:               uart_putchar(USART_1,0xA5);       // ����1����0xA5
//-------------------------------------------------------------------------------------------------------------------
void uart_putchar(UARTN_enum uartn, uint8 dat)
{
    while (!(UARTN[uartn]->STAT & LPUART_STAT_TDRE_MASK));
    LPUART_WriteByte(UARTN[uartn],dat);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ���ڷ�������
//  @param      uartn           ����ģ���(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      *buff           Ҫ���͵������ַ
//  @param      len             ���ͳ���
//  @return     void
//  Sample usage:               uart_putbuff(USART_1,&a[0],5);
//-------------------------------------------------------------------------------------------------------------------
void uart_putbuff(UARTN_enum uartn, uint8 *buff, uint32 len)
{
    LPUART_WriteBlocking(UARTN[uartn], buff, len);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ���ڷ����ַ���
//  @param      uartn           ����ģ���(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      *str            Ҫ���͵��ַ�����ַ
//  @return     void
//  Sample usage:               uart_putstr(USART_1,"i lvoe you"); 
//-------------------------------------------------------------------------------------------------------------------
void uart_putstr(UARTN_enum uartn, const uint8 *str)
{
    while(*str)
    {
        uart_putchar(uartn, *str++);
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ȡ���ڽ��յ����ݣ�whlie�ȴ���
//  @param      uartn           ����ģ���(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      *dat            �������ݵĵ�ַ
//  @return     void        
//  Sample usage:               uint8 dat; uart_getchar(USART_1,&dat);       // ���մ���1����  ������dat������
//-------------------------------------------------------------------------------------------------------------------
void uart_getchar(UARTN_enum uartn, uint8 *dat)
{
    while ((UARTN[uartn]->WATER & LPUART_WATER_RXCOUNT_MASK) >> LPUART_WATER_RXCOUNT_SHIFT);
    *dat = LPUART_ReadByte(UARTN[uartn]);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ȡ���ڽ��յ����ݣ���ѯ���գ�
//  @param      uartn           ����ģ���(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      *dat            �������ݵĵ�ַ
//  @return     uint8           1�����ճɹ�   0��δ���յ�����
//  Sample usage:               uint8 dat; uart_query(USART_1,&dat);       // ���մ���1����  ������dat������
//-------------------------------------------------------------------------------------------------------------------
uint8 uart_query(UARTN_enum uartn, uint8 *dat)
{
    if((UARTN[uartn]->WATER & LPUART_WATER_RXCOUNT_MASK) >> LPUART_WATER_RXCOUNT_SHIFT)
    {
        *dat = LPUART_ReadByte(UARTN[uartn]);
        return 1;
    }
    return 0;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ���ڷ��Ϳ����ж�����
//  @param      uartn           ����ģ���(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      status          1�����ж�   0���ر��ж�
//  @return     void        
//  Sample usage:               uart_tx_irq(USART_1,1);       // �򿪴���1��������ж�
//-------------------------------------------------------------------------------------------------------------------
void uart_tx_irq(UARTN_enum uartn,uint8 status)
{
    if(status)  
    {
        LPUART_EnableInterrupts(UARTN[uartn], kLPUART_TransmissionCompleteInterruptEnable);
    }
    else
    {
        LPUART_DisableInterrupts(UARTN[uartn], kLPUART_TransmissionCompleteInterruptEnable);
    }
    
    //NVIC_SetPriority((IRQn_Type)((IRQn_Type)(uartn) + LPUART1_IRQn),0);//���ȼ����� ��Χ0-15 ԽС���ȼ�Խ��
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ���ڽ����ж�����
//  @param      uartn           ����ģ���(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      *handle			�����жϽṹ�����	
//  @param      *callback		�жϺ���Ҫִ�еĺ���
//  @param      *tx_buff		��Ҫ�������ݵĵ�ַ
//  @param      *tx_count	    ��Ҫ���͵��ֽ���
//  @param      *rx_buff		��Ҫ�������ݵĵ�ַ
//  @param      *rx_count		��Ҫ���յ��ֽ���	
//  @return     void        
//  Sample usage:               uart_set_handle(USART_1, &csi_g_lpuartHandle, uart1_call_back, NULL, 0, buff, 1);//����1 ���жϻص���������Ϊuart1_call_back ����Ҫ�����ж� ���ջ���Ϊbuff ���յ�1���ֽھ��ж�
//-------------------------------------------------------------------------------------------------------------------
void uart_rx_irq(UARTN_enum uartn,uint8 status)
{
    if(status)  
    {
        LPUART_EnableInterrupts(UARTN[uartn], kLPUART_RxDataRegFullInterruptEnable);
    }
    else
    {
        LPUART_DisableInterrupts(UARTN[uartn], kLPUART_RxDataRegFullInterruptEnable);
    }
    //NVIC_SetPriority((IRQn_Type)((IRQn_Type)(uartn) + LPUART1_IRQn),0);//���ȼ����� ��Χ0-15 ԽС���ȼ�Խ��
}

void uart_set_handle(UARTN_enum uartn, lpuart_handle_t *handle, lpuart_transfer_callback_t callback, uint8 *tx_buff, uint32 tx_count, uint8 *rx_buff, uint32 rx_count)
{
    LPUART_TransferCreateHandle(UARTN[uartn], handle, callback, NULL);
    //���ý��ջ������뷢�ͻ�����
    handle->txData = tx_buff;
    handle->txDataSize = tx_count;
    handle->rxData = rx_buff;
    handle->rxDataSize = rx_count;
    
}


