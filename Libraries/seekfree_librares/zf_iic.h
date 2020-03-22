/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		iic
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
 
#ifndef _zf_iic_h
#define _zf_iic_h

#include "common.h"
#include "fsl_lpi2c.h"

//��ö�ٶ��岻�����û��޸�
typedef enum //ö��IIC����
{
    IIC1_SDA_B31,  IIC1_SDA_C3 ,
    IIC1_SCL_B30,  IIC1_SCL_C2 ,
                               
    IIC2_SDA_B25,  IIC2_SDA_C18,
    IIC2_SCL_B24,  IIC2_SCL_C19,
                               
    IIC3_SDA_B9 ,  IIC3_SDA_D14,
    IIC3_SCL_B8 ,  IIC3_SCL_D13,
                              
    IIC4_SDA_C10,  IIC4_SDA_D23,
    IIC4_SCL_C11,  IIC4_SCL_D22,
    
}IIC_PIN_enum;

//��ö�ٶ��岻�����û��޸�
typedef enum //ö��IIC���
{
    IIC_0,//RT1021û��IIC_0 ���������ռλ
    IIC_1,
    IIC_2,
    IIC_3,
    IIC_4,
}IICN_enum;



void iic_init(IICN_enum iic_n, IIC_PIN_enum sda_pin, IIC_PIN_enum scl_pin, uint32 baud);
uint8 iic_write_reg(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 data);
uint8 iic_read_reg(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 *data);
uint8 iic_read_reg_bytes(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 *data, uint8 num);


#endif