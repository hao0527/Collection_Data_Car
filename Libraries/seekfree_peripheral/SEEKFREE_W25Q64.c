/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		W25Q64 FLASH
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-07-17
 * @note		
					���߶��壺
					------------------------------------ 
						оƬ�ܽ�            ��Ƭ���ܽ�
                        
						CLK                 �鿴FLASH_SPI_SCK_PIN�궨�������     Ӳ��SPI���Ų��������л�
						DI                  �鿴FLASH_SPI_MOSI_PIN�궨�������    Ӳ��SPI���Ų��������л�
						DO                  �鿴FLASH_SPI_MISO_PIN�궨�������    Ӳ��SPI���Ų��������л�
						CS                  �鿴FLASH_SPI_CS_PIN�궨�������      
                    
                        VCC                 3.3V
                        GND                 GND
                        WP                  3.3V
                        HOLD                3.3V

 ********************************************************************************************************************/

#include "zf_spi.h"
#include "zf_gpio.h"
#include "zf_iomuxc.h"
#include "zf_systick.h"
#include "SEEKFREE_W25Q64.h"


//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_spi_reg_bytes(uint8 * val, uint16 num)
{
    gpio_set(FLASH_SPI_CS_PIN,0);
    spi_mosi(FLASH_SPI_NUM,SPI_CS_NOT_USE,val,val,num,1);
    gpio_set(FLASH_SPI_CS_PIN,1);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
uint8 w25qxx_read_status(void)
{
    struct
    {
        uint8 instruction;  //ָ��
        uint8 status;   
    }buf;
    buf.instruction = 0x05;
    w25qxx_spi_reg_bytes(&buf.instruction, 2);
    return buf.status;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
uint8 w25qxx_read_status2(void)
{
    struct
    {
        uint8 instruction;  //ָ��
        uint8 status;   
    }buf;
    buf.instruction = 0x35;
    w25qxx_spi_reg_bytes(&buf.instruction, 2);
    return buf.status;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//  @note    	����FV��׺оƬ�� ״̬�Ĵ���д��
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_write_status1(uint16 status)
{
    struct
    {
        uint8 instruction;  //ָ��
        uint8 status1;   
        uint8 status2;   
    }buf;
    buf.instruction = 0x01;
    buf.status1 = status&0xff;
    buf.status2 = status>>8;
    
    w25qxx_spi_reg_bytes(&buf.instruction, 3);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//  @note    	����JV��׺оƬ�� ״̬�Ĵ���д��
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_write_status2(uint8 status)
{
    struct
    {
        uint8 instruction;  //ָ��
        uint8 status;   
    }buf;
    buf.instruction = 0x31;
    buf.status = status;
    
    w25qxx_spi_reg_bytes(&buf.instruction, 2);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_write_enable(void)
{
    uint8 instruction;

    instruction = 0x06;
    w25qxx_spi_reg_bytes(&instruction, 1);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_wait_busy(void)
{
    uint8 status;
    uint8 isBusy;
    
    do
    {
        status = w25qxx_read_status();
        isBusy = status&0x01;
    }
    while(isBusy);
    
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��������falsh
//  @param      void
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note                   
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_erase_chip(void)
{
    uint8 instruction;

    instruction = 0x06;
    
    w25qxx_write_enable();
    w25qxx_spi_reg_bytes(&instruction, 1);
    w25qxx_wait_busy();
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ����һ������
//  @param      sector      �������                W25Q64XX ������Χ��0-2047
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note                   ��Ҫע�� W25Q64XX sector������Χ��0-2047 
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_erase_sector(uint32 sector)
{
    struct
    {
        uint8 instruction;  //ָ��
        uint8 address[3];   //24λ��ַ
    }buf;
    buf.instruction = 0x20;
    buf.address[0] = (sector * SECTOR_SIZE1)>>16&0xff;
    buf.address[1] = (sector * SECTOR_SIZE1)>>8&0xff;
    buf.address[2] = (sector * SECTOR_SIZE1)&0xff;
    w25qxx_write_enable();
    w25qxx_spi_reg_bytes(&buf.instruction, 4);
    w25qxx_wait_busy();
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      д�����ݵ�ָ������ ָ��ҳ��
//  @param      sector      �������                W25Q64XX ������Χ��0-2047
//  @param      page        �����ڼ�ҳ              ������Χ0-15
//  @param      *dat        ���ݴ洢��ַ
//  @param      length      ��ȡ���ݵ��ֽ���        ������Χ1-256
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note                   ��Ҫע�� W25Q64XX sector������Χ��0-2047 
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_read_page(uint16 sector, uint16 page, uint8 *dat, uint16 length)
{
    uint16 i;
    struct
    {
        uint8 instruction;  //ָ��
        uint8 address[4];   //24λ��ַ
        uint8 dat_buf[256]; //���ݻ�����
    }buf;
    buf.instruction = 0x0b;
    buf.address[0] = (sector * SECTOR_SIZE1)>>16&0xff;
    buf.address[1] = (sector * SECTOR_SIZE1)>>8&0xff;
    buf.address[2] = (sector * SECTOR_SIZE1)&0xff;
    buf.address[3] = 0;     //dummy clocks
    
    w25qxx_spi_reg_bytes(&buf.instruction, 5+length);
    
    i=0;
    while(i<length)
    {
        dat[i] = buf.dat_buf[i];
        i++;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ���ָ��ҳ�Ƿ�Ϊȫ�հ�
//  @param      sector      �������                W25Q64XX ������Χ��0-2047
//  @param      page        �����ڼ�ҳ              ������Χ0-15
//  @return     uint8       0:ҳΪȫ�հ�  1����ҳ������
//  @since      v1.0
//  Sample usage:
//  @note                   ��Ҫע�� W25Q64XX sector������Χ��0-2047 
//-------------------------------------------------------------------------------------------------------------------
uint8 w25qxx_check_page(uint16 sector, uint16 page)
{
    uint16 i;
    uint8 buf[256];
    
    w25qxx_read_page(sector,page,buf,256);
    i=0;
    while(i<256)
    {
        if(0xff != buf[i])  return 1;
		i++;
    }
    return 0;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      д�����ݵ�ָ������ ָ��ҳ��
//  @param      sector      �������                W25Q64XX ������Χ��0-2047
//  @param      page        �����ڼ�ҳ              ������Χ0-15
//  @param      *dat        д�����ݵĵ�ַ          
//  @param      length      д�����ݵ��ֽ���        ������Χ1-256
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note                   ��Ҫע�� W25Q64XX sector������Χ��0-2047 
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_write_page(uint16 sector, uint16 page, uint8 *dat, uint16 length)
{
    uint16 i;
    struct
    {
        uint8 instruction;  //ָ��
        uint8 address[3];   //24λ��ַ
        uint8 dat_buf[256]; //���ݻ�����
    }buf;
    buf.instruction = 0x02;
    buf.address[0] = (sector * SECTOR_SIZE1)>>16&0xff;
    buf.address[1] = (sector * SECTOR_SIZE1)>>8&0xff;
    buf.address[2] = (sector * SECTOR_SIZE1)&0xff;
    
    i=0;
    while(i<length)
    {
        buf.dat_buf[i] = dat[i];
        i++;
    }
    
    w25qxx_write_enable();
    w25qxx_spi_reg_bytes(&buf.instruction, 4+length);
    w25qxx_wait_busy();
}




//-------------------------------------------------------------------------------------------------------------------
//  @brief      flash��ʼ��
//  @param      sector      �������
//  @param      page        �����ڼ�ҳ ������Χ0-15
//  @param      *dat        ���ݴ洢��ַ
//  @param      length      ��ȡ���ݵ��ֽ���
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note                   ��Ҫ�Լ����falshоƬ����ν��߲鿴���Ϸ����߶��塣 �Լ�������ʱ  �����flashоƬ�ĵ�Դ���Ÿ�������һ��0.1uf�ĵ��ݺ�һ��10uf�ĵ���
//							�м����ﲢ���ǲ������İ��ϵ�flash������Ҫ�Լ����һ��flashȻ�������в�����
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_init(void)
{
    uint16 status2;
    
    //������Ҫע�⣬flash���õ���SPI����ICM�õ���SPI��һ���ģ�����ͨ��CS����������SPI���ʲ�ͬ��ģ��
    //�����õ���CS���������ģ��ģ����������޸�
    (void)spi_init(FLASH_SPI_NUM, FLASH_SPI_SCK_PIN, FLASH_SPI_MOSI_PIN, FLASH_SPI_MISO_PIN, SPI_CS_NOT_USE, 3, 10*1000*1000);//Ӳ��SPI��ʼ��
    gpio_init(FLASH_SPI_CS_PIN,GPO,1,GPIO_PIN_CONFIG);
    
    
    status2 = w25qxx_read_status2();
    
    if(status2&0x02)//���Quad Enable����ر�
    {
        status2 &= ~0x02;//QEλ ����
		w25qxx_write_status2(status2);//JV��׺��оƬ�ô�����
		status2 = w25qxx_read_status2();
		//FV��׺��оƬ�����´���
		//status2 <<= 8;
		//status2 |= w25qxx_read_status();
		//w25qxx_write_status1(status2);
    }
    
}


