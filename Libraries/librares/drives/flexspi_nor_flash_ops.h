
#ifndef _flexspi_nor_flash_ops_H_
#define _flexspi_nor_flash_ops_H_

#include "common.h"


#define EXAMPLE_FLEXSPI         FLEXSPI
#define FLASH_SIZE              0x2000  //64Mb=8MB
#define FLASH_PAGE_SIZE         256     //页大小256字节
#define FLASH_SECTOR_NUM        2048    //扇区数量
#define FLASH_SECTOR_SIZE       0x1000  //扇区数量4KB
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
