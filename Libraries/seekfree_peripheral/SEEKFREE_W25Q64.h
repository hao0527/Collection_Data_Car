/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		W25Q64FV FLASH
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


#include "common.h"



#define FLASH_SPI_NUM         SPI_2           
#define FLASH_SPI_SCK_PIN     SPI2_SCK_C10    //��ģ��CLK
#define FLASH_SPI_MOSI_PIN    SPI2_MOSI_C12   //��ģ��DI
#define FLASH_SPI_MISO_PIN    SPI2_MISO_C13   //��ģ��DO
#define FLASH_SPI_CS_PIN      D23             //��ģ��CS


//W25Q64 �����������Ϊ2048 
//W25Q32 �����������Ϊ1024 
//W25Q16 �����������Ϊ512
#define SECTOR_NUM          2048   

#define SECTOR_SIZE1        4096    //������С ��λ���ֽ�
#define PAGE_SIZE           256     //ҳ��С   ��λ���ֽ�   
#define SECTOR_PAGE_NUM     16      //һ������ҳ������  (SECTOR_SIZE/FLASH_PAGE_SIZE)


void w25qxx_erase_chip(void);
void w25qxx_erase_sector(uint32 sector);
void w25qxx_read_page(uint16 sector, uint16 page, uint8 *dat, uint16 length);
uint8 w25qxx_check_page(uint16 sector, uint16 page);
void w25qxx_write_page(uint16 sector, uint16 page, uint8 *dat, uint16 length);
void w25qxx_init(void);













