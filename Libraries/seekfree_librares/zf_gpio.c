/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		gpio
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
 

#include "fsl_gpio.h"
#include "fsl_iomuxc.h"
#include "zf_iomuxc.h"
#include "zf_gpio.h"

GPIO_Type * PORTPTR[] = GPIO_BASE_PTRS;




//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO��ʼ��
//  @param      pin         ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
//  @param      dir         ���ŵķ���   �����GPO   ���룺GPI
//  @param      dat         ���ų�ʼ��ʱ���õĵ�ƽ״̬�����ʱ��Ч 0���͵�ƽ 1���ߵ�ƽ
//  @param      pinconf     �������ã������ò�����zf_iomuxc.h�ļ���PINCONF_enumö��ֵȷ�����������ʹ�� | ���
//  @return     void
//  Sample usage:           gpio_init(D5, GPO, 1, GPIO_PIN_CONFIG);//D5��ʼ��ΪGPIO���ܡ����ģʽ������ߵ�ƽ������47K IO�ٶ�100MHZ ����ǿ��R0
//-------------------------------------------------------------------------------------------------------------------
void gpio_init(PIN_enum pin, GPIODIR_enum dir, uint8 dat, uint32 pinconf)
{
    gpio_pin_config_t gpio_config;

    if(GPO == dir)      gpio_config.direction = kGPIO_DigitalOutput; 
    else if(GPI == dir) gpio_config.direction = kGPIO_DigitalInput;
    
    if(dat)     gpio_config.outputLogic =  1;
    else        gpio_config.outputLogic =  0;

    gpio_config.interruptMode = (gpio_interrupt_mode_t)NO_INT; //��ʹ���ж�
    iomuxc_pinconf(pin,ALT5,pinconf);

    GPIO_PinInit(PORTPTR[pin>>5], pin&0x1f, &gpio_config);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO�������
//  @param      pin         ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
//  @param      dat         0���͵�ƽ 1���ߵ�ƽ
//  @return     void
//  Sample usage:           gpio_set(D5,1);//D5 ����ߵ�ƽ
//-------------------------------------------------------------------------------------------------------------------
void gpio_set(PIN_enum pin, uint8 dat)
{
    if(dat) GPIO_SetPinsOutput(PORTPTR[pin>>5],1<<(pin&0x1f));
    else    GPIO_ClearPinsOutput(PORTPTR[pin>>5],1<<(pin&0x1f));
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO�������
//  @param      pin         ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
//  @return     uint8       0���͵�ƽ 1���ߵ�ƽ
//  Sample usage:           uint8 status = gpio_get(D5);//��ȡD5���ŵ�ƽ
//-------------------------------------------------------------------------------------------------------------------
uint8 gpio_get(PIN_enum pin)
{
    return (GPIO_ReadPadStatus(PORTPTR[pin>>5],pin&0x1f));
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO��������
//  @param      pin         ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
//  @param      dir         ���ŵķ���   �����GPO   ���룺GPI
//  @return     void        
//  Sample usage:           gpio_dir(D5,GPO);//����D5Ϊ���ģʽ
//-------------------------------------------------------------------------------------------------------------------
void gpio_dir(PIN_enum pin, GPIODIR_enum dir)
{
    if (GPI == dir) PORTPTR[pin>>5]->GDIR &= ~(1U << (pin&0x1f));
    else            PORTPTR[pin>>5]->GDIR |= (1U << (pin&0x1f));
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO ��ת
//  @param      pin         ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
//  @return     void        
//  Sample usage:           gpio_toggle(D5);//D5���ŵ�ƽ��ת
//-------------------------------------------------------------------------------------------------------------------
void gpio_toggle(PIN_enum pin)
{
    GPIO_PortToggle(PORTPTR[pin>>5],1<<(pin&0x1f));
}






//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO �ⲿ�жϳ�ʼ��
//  @param      pin         ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
//  @param      trigger     �жϴ�����ʽ ѡ��Χ�μ�h�ļ�TRIGGER_enumö��
//  @param      pinconf     �������� �������ò�����zf_iomuxc.h�ļ���PINCONF_enumö��ֵȷ�����������ʹ�� | ���
//  @return     void        
//  Sample usage:           gpio_interrupt_init(D5,RISING,GPIO_INT_CONFIG);//D5�������ж�
//-------------------------------------------------------------------------------------------------------------------
void gpio_interrupt_init(PIN_enum pin, TRIGGER_enum trigger, uint32 pinconf)
{
    gpio_pin_config_t gpio_config;

    iomuxc_pinconf(pin,ALT5,pinconf);                           //�������Ÿ���
    gpio_config.direction = kGPIO_DigitalInput;
    gpio_config.interruptMode = (gpio_interrupt_mode_t)trigger;
    GPIO_PinInit(PORTPTR[pin>>5], pin&0x1f, &gpio_config);      //��ʼ��GPIO
    GPIO_PortEnableInterrupts(PORTPTR[pin>>5],1<<(pin&0x1f));   //��GPIO���ж�

    EnableIRQ((IRQn_Type)((IRQn_Type)((pin>>4)-2) + GPIO1_Combined_0_15_IRQn));//ʹ��IRQ
    
    //NVIC_SetPriority((IRQn_Type)((IRQn_Type)((pin>>4)-2) + GPIO1_Combined_0_15_IRQn),0);//���ȼ����� ��Χ0-15 ԽС���ȼ�Խ��
}

