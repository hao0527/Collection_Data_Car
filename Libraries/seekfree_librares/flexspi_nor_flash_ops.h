/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		flexspi_nor_flash
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
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
#define FLASH_PAGE_SIZE         256     //页大小256字节
#define FLASH_SECTOR_NUM        2048    //扇区数量
#define FLASH_SECTOR_SIZE       4096    //扇区数量4KB
#define FLASH_SECTOR_PAGE_NUM   (FLASH_SECTOR_SIZE/FLASH_PAGE_SIZE)//一个扇区下页的数量
#define EXAMPLE_FLEXSPI_CLOCK   kCLOCK_FlexSpi
#define FLASH_BASE_ADDR         FlexSPI_AMBA_BASE




extern status_t flexspi_nor_flash_erase_sector(FLEXSPI_Type *base, uint32_t address);
extern status_t flexspi_nor_flash_page_program(FLEXSPI_Type *base, uint32_t dstAddr, const uint32_t *src, uint8 len);
extern status_t flexspi_nor_get_vendor_id(FLEXSPI_Type *base, uint8_t *vendorId);
extern status_t flexspi_nor_enable_quad_mode(FLEXSPI_Type *base);
//extern status_t flexspi_nor_erase_chip(FLEXSPI_Type *base);
extern status_t flexspi_nor_init(void);



#endif 
