/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		flexspi_nor_flash
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-12-31
 ********************************************************************************************************************/



#ifndef _flexspi_nor_flash_ops_H_
#define _flexspi_nor_flash_ops_H_

#include "common.h"


#define EXAMPLE_FLEXSPI         FLEXSPI
#define FLASH_SIZE              0x2000  //64Mb=8MB
#define FLASH_PAGE_SIZE         256     //ҳ��С256�ֽ�
#define FLASH_SECTOR_NUM        2048    //��������
#define FLASH_SECTOR_SIZE       4096    //��������4KB
#define FLASH_SECTOR_PAGE_NUM   (FLASH_SECTOR_SIZE/FLASH_PAGE_SIZE)//һ��������ҳ������
#define EXAMPLE_FLEXSPI_CLOCK   kCLOCK_FlexSpi
#define FLASH_BASE_ADDR         FlexSPI_AMBA_BASE




extern status_t flexspi_nor_flash_erase_sector(FLEXSPI_Type *base, uint32_t address);
extern status_t flexspi_nor_flash_page_program(FLEXSPI_Type *base, uint32_t dstAddr, const uint32_t *src, uint8 len);
extern status_t flexspi_nor_get_vendor_id(FLEXSPI_Type *base, uint8_t *vendorId);
extern status_t flexspi_nor_enable_quad_mode(FLEXSPI_Type *base);
//extern status_t flexspi_nor_erase_chip(FLEXSPI_Type *base);
extern status_t flexspi_nor_init(void);



#endif 
