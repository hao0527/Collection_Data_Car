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

#include "zf_iomuxc.h"
#include "zf_iic.h"
 
#define IIC_PIN_CONF  SPEED_100MHZ | KEEPER_EN | PULLUP_22K | DSE_R0_6 | OD_EN  //����IIC����Ĭ������


LPI2C_Type * IICN[] = LPI2C_BASE_PTRS;

#define LPI2C_CLOCK_SOURCE_DIVIDER (0x05)

#define LPI2C_CLOCK_FREQUENCY ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (LPI2C_CLOCK_SOURCE_DIVIDER + 1))



void iic_iomuxc(IICN_enum iic_n, IIC_PIN_enum sda_pin, IIC_PIN_enum scl_pin)
{
    switch(iic_n)
    {
        case IIC_1:
        {
            if      (IIC1_SDA_B31 == sda_pin) iomuxc_pinconf(B31 ,ALT0,IIC_PIN_CONF);
            else if (IIC1_SDA_C3  == sda_pin) iomuxc_pinconf(C3  ,ALT6,IIC_PIN_CONF);
            else    assert(0);
            
            if      (IIC1_SCL_B30 == scl_pin) iomuxc_pinconf(B30 ,ALT0,IIC_PIN_CONF);
            else if (IIC1_SCL_C2  == scl_pin) iomuxc_pinconf(C2  ,ALT6,IIC_PIN_CONF);
            else    assert(0);
        }break;
        
        case IIC_2:
        {
            if      (IIC2_SDA_B25 == sda_pin) iomuxc_pinconf(B25 ,ALT0,IIC_PIN_CONF);
            else if (IIC2_SDA_C18 == sda_pin) iomuxc_pinconf(C18 ,ALT2,IIC_PIN_CONF);
            else    assert(0);                               
                                                             
            if      (IIC2_SCL_B24 == scl_pin) iomuxc_pinconf(B24 ,ALT0,IIC_PIN_CONF);
            else if (IIC2_SCL_C19 == scl_pin) iomuxc_pinconf(C19 ,ALT2,IIC_PIN_CONF);
            else    assert(0);
        }break;
        
        case IIC_3:
        {
            if      (IIC3_SDA_B9  == sda_pin) iomuxc_pinconf(B9  ,ALT1,IIC_PIN_CONF);
            else if (IIC3_SDA_D14 == sda_pin) iomuxc_pinconf(D14 ,ALT4,IIC_PIN_CONF);
            else    assert(0);                                  
                                                                
            if      (IIC3_SCL_B8  == scl_pin) iomuxc_pinconf(B8  ,ALT1,IIC_PIN_CONF);
            else if (IIC3_SCL_D13 == scl_pin) iomuxc_pinconf(D13 ,ALT4,IIC_PIN_CONF);
            else    assert(0);
        }break;
        
        case IIC_4:
        {
            if      (IIC4_SDA_C10 == sda_pin) iomuxc_pinconf(C10 ,ALT2,IIC_PIN_CONF);
            else if (IIC4_SDA_D23 == sda_pin) iomuxc_pinconf(D23 ,ALT3,IIC_PIN_CONF);
            else    assert(0);                                  
                                                                
            if      (IIC4_SCL_C11 == scl_pin) iomuxc_pinconf(C11 ,ALT2,IIC_PIN_CONF);
            else if (IIC4_SCL_D22 == scl_pin) iomuxc_pinconf(D22 ,ALT3,IIC_PIN_CONF);
            else    assert(0);
        }break;
        
        default:assert(0);break;
    }
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      IIC��ʼ��
//  @param      iic_n           IICģ��(IIC_1,IIC_2,IIC_3,IIC_4)
//  @param      sda_pin         ѡ��IIC��������
//  @param      scl_pin         ѡ��IICʱ������
//  @param      baud            ����IIC�Ĳ�����
//  @return     void
//  Sample usage:               iic_init(IIC_2, IIC2_SDA_B25, IIC2_SCL_B24,400*1000);//Ӳ��IIC��ʼ��     
//-------------------------------------------------------------------------------------------------------------------
void iic_init(IICN_enum iic_n, IIC_PIN_enum sda_pin, IIC_PIN_enum scl_pin, uint32 baud)
{
    lpi2c_master_config_t masterConfig;
    
    iic_iomuxc(iic_n, sda_pin, scl_pin);

    CLOCK_SetMux(kCLOCK_Lpi2cMux, 0);
    CLOCK_SetDiv(kCLOCK_Lpi2cDiv, LPI2C_CLOCK_SOURCE_DIVIDER);
    
    /*
     * masterConfig.debugEnable = false;
     * masterConfig.ignoreAck = false;
     * masterConfig.pinConfig = kLPI2C_2PinOpenDrain;
     * masterConfig.baudRate_Hz = 100000U;
     * masterConfig.busIdleTimeout_ns = 0;
     * masterConfig.pinLowTimeout_ns = 0;
     * masterConfig.sdaGlitchFilterWidth_ns = 0;
     * masterConfig.sclGlitchFilterWidth_ns = 0;
     */
    LPI2C_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate_Hz = baud;
    LPI2C_MasterInit(IICN[iic_n], &masterConfig, LPI2C_CLOCK_FREQUENCY);//��һ�γ�ʼ�����ڴ�ʱ��
    LPI2C_MasterReset(IICN[iic_n]);                                     //��λ����
    LPI2C_MasterInit(IICN[iic_n], &masterConfig, LPI2C_CLOCK_FREQUENCY);//���³�ʼ��������ȷ�Ĳ���
    
    
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      д��һ���ֽ����ݵ�I2C�豸ָ���Ĵ�����ַ
//  @param      iic_n       IICģ��(IIC_1,IIC_2,IIC_3,IIC_4)
//  @param      slaveid     �ӻ���ַ(7λ��ַ)
//  @param      reg         �ӻ��Ĵ�����ַ
//  @param      data        ��Ҫ���͵�����
//  @return                 ���ص�״ֵ̬ 0���ɹ�  1��ʧ��
//  @since      v2.0
//  Sample usage:       	iic_write_reg(IIC_2, 0x2D, 0x50,2);     //д������2��0x50��ַ���ӻ���ַΪ0x2D
//-------------------------------------------------------------------------------------------------------------------
uint8 iic_write_reg(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 data)
{
    status_t reVal = kStatus_Fail;
    
    reVal = LPI2C_MasterStart(IICN[iic_n], slaveid, kLPI2C_Write);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    while (LPI2C_MasterGetStatusFlags(IICN[iic_n]) & kLPI2C_MasterNackDetectFlag);
    
    reVal = LPI2C_MasterSend(IICN[iic_n], &reg, 1);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterSend(IICN[iic_n], &data, 1);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterStop(IICN[iic_n]);
    if (reVal != kStatus_Success)   return kStatus_Fail;

    return kStatus_Success;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ȡI2C�豸ָ����ַ�Ĵ���������
//  @param      iic_n       IICģ��(IIC_1,IIC_2,IIC_3,IIC_4)
//  @param      slaveid     �ӻ���ַ(7λ��ַ)
//  @param      reg         �ӻ��Ĵ�����ַ
//  @param      *data       ��ȡ����������
//  @return                 ���ص�״ֵ̬ 0���ɹ�  1��ʧ��
//  @since      v2.0
//  Sample usage:       	uint8 value = iic_read_reg(IIC_2, 0x2D, 0x50);//��ȡ0x50��ַ�����ݣ��ӻ���ַΪ0x2D
//-------------------------------------------------------------------------------------------------------------------
uint8 iic_read_reg(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 *data)
{
    status_t reVal = kStatus_Fail;

    reVal = LPI2C_MasterStart(IICN[iic_n], slaveid, kLPI2C_Write);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    while (LPI2C_MasterGetStatusFlags(IICN[iic_n]) & kLPI2C_MasterNackDetectFlag);
    
    reVal = LPI2C_MasterSend(IICN[iic_n], &reg, 1);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterRepeatedStart(IICN[iic_n], slaveid, kLPI2C_Read);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterReceive(IICN[iic_n], data, 1);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterStop(IICN[iic_n]);
    if (reVal != kStatus_Success)   return kStatus_Fail;

    return kStatus_Success;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ȡI2C�豸ָ����ַ�Ĵ���������
//  @param      iic_n       IICģ��(IIC_1,IIC_2,IIC_3,IIC_4)
//  @param      slaveid     �ӻ���ַ(7λ��ַ)
//  @param      reg         �ӻ��Ĵ�����ַ
//  @param      data        ��ȡ�����ݴ洢�ĵ�ַ
//  @param      num         ��ȡ�ֽ���
//  @return                 ���ص�״ֵ̬ 0���ɹ�  1��ʧ��
//  @since      v2.0
//  Sample usage:       	uint8 value = iic_read_reg(IIC_2, 0x2D, 0x50, 10, buf);//��ȡ0x50��ַ�����ݣ��ӻ���ַΪ0x2D��ʼ��10���ֽ�
//-------------------------------------------------------------------------------------------------------------------
uint8 iic_read_reg_bytes(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 *data, uint8 num)
{
    status_t reVal = kStatus_Fail;
    
    reVal = LPI2C_MasterStart(IICN[iic_n], slaveid, kLPI2C_Write);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    while (LPI2C_MasterGetStatusFlags(IICN[iic_n]) & kLPI2C_MasterNackDetectFlag);
    
    reVal = LPI2C_MasterSend(IICN[iic_n], &reg, 1);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterRepeatedStart(IICN[iic_n], slaveid, kLPI2C_Read);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterReceive(IICN[iic_n], data, num);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterStop(IICN[iic_n]);
    if (reVal != kStatus_Success)   return kStatus_Fail;

    return kStatus_Success;
}