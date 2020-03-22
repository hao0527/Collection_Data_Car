/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		spi
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 

#include "zf_iomuxc.h"
#include "zf_spi.h"


#define LPSPI_PIN_CONF  SPEED_100MHZ | KEEPER_EN | DSE_R0_6 //����SPI����Ĭ������
#define LPSPI_CLK_DIV   3
#define LPSPI_CLK_SRC   2



LPSPI_Type * SPIN[] = LPSPI_BASE_PTRS;

void spi_iomuxc(SPIN_enum spi_n, SPI_PIN_enum sck_pin, SPI_PIN_enum mosi_pin, SPI_PIN_enum miso_pin, SPI_PIN_enum cs_pin)
{
    switch(spi_n)
    {
        case SPI_1:
        {
            if      (SPI1_SCK_B10  == sck_pin)  iomuxc_pinconf(B10,ALT1,LPSPI_PIN_CONF);
            else if (SPI1_SCK_D15  == sck_pin)  iomuxc_pinconf(D15,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
            
            if      (SPI1_MOSI_B12 == mosi_pin) iomuxc_pinconf(B12,ALT1,LPSPI_PIN_CONF);
            else if (SPI1_MOSI_D17 == mosi_pin) iomuxc_pinconf(D17,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
                                                               
            if      (SPI1_MISO_B13 == miso_pin) iomuxc_pinconf(B13,ALT1,LPSPI_PIN_CONF);
            else if (SPI1_MISO_D18 == miso_pin) iomuxc_pinconf(D18,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
            
            if      (SPI1_CS0_B11  == cs_pin)   iomuxc_pinconf(B11,ALT1,LPSPI_PIN_CONF);
            else if (SPI1_CS0_D16  == cs_pin)   iomuxc_pinconf(B20,ALT4,LPSPI_PIN_CONF);
            else if (SPI1_CS1_B20  == cs_pin)   iomuxc_pinconf(B20,ALT6,LPSPI_PIN_CONF);
            else if (SPI1_CS2_B21  == cs_pin)   iomuxc_pinconf(B21,ALT6,LPSPI_PIN_CONF);
            else if (SPI1_CS3_B22  == cs_pin)   iomuxc_pinconf(B22,ALT6,LPSPI_PIN_CONF);
            else if (SPI_CS_NOT_USE  == cs_pin)   ;//��ʹ��Ƭѡ����
            else                                assert(0);//���Ŵ��� �������ʧ��
        }break;
        
        case SPI_2:
        {
            if      (SPI2_SCK_C0   == sck_pin)  iomuxc_pinconf(C0 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_SCK_C10  == sck_pin)  iomuxc_pinconf(C10,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_SCK_D27  == sck_pin)  iomuxc_pinconf(D27,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
            
            if      (SPI2_MOSI_C2  == mosi_pin) iomuxc_pinconf(C2 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_MOSI_C12 == mosi_pin) iomuxc_pinconf(C12,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_MOSI_D28 == mosi_pin) iomuxc_pinconf(D28,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
                                                               
            if      (SPI2_MISO_C3  == miso_pin) iomuxc_pinconf(C3 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_MISO_C13 == miso_pin) iomuxc_pinconf(C13,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_MISO_D29 == miso_pin) iomuxc_pinconf(D29,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
            
            if      (SPI2_CS0_C1   == cs_pin)   iomuxc_pinconf(C1 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_CS0_C11  == cs_pin)   iomuxc_pinconf(C11,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_CS0_D26  == cs_pin)   iomuxc_pinconf(D26,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_CS1_C14  == cs_pin)   iomuxc_pinconf(C14,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_CS2_D30  == cs_pin)   iomuxc_pinconf(D30,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_CS3_D31  == cs_pin)   iomuxc_pinconf(D31,ALT4,LPSPI_PIN_CONF);
            else if (SPI_CS_NOT_USE  == cs_pin)   ;//��ʹ��Ƭѡ����
            else                                assert(0);//���Ŵ��� �������ʧ��
        }break;
        
        case SPI_3:
        {
            if      (SPI3_SCK_B28  == sck_pin)  iomuxc_pinconf(B28,ALT2,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
            
            if      (SPI3_MOSI_B30 == mosi_pin) iomuxc_pinconf(B30,ALT2,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
                                                               
            if      (SPI3_MISO_B31 == miso_pin) iomuxc_pinconf(B31,ALT2,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
            
            if      (SPI3_CS0_B29  == cs_pin)   iomuxc_pinconf(B29,ALT2,LPSPI_PIN_CONF);
            else if (SPI3_CS1_B25  == cs_pin)   iomuxc_pinconf(B25,ALT6,LPSPI_PIN_CONF);
            else if (SPI3_CS2_B24  == cs_pin)   iomuxc_pinconf(B24,ALT6,LPSPI_PIN_CONF);
            else if (SPI3_CS3_B23  == cs_pin)   iomuxc_pinconf(B23,ALT6,LPSPI_PIN_CONF);
            else if (SPI_CS_NOT_USE  == cs_pin)   ;//��ʹ��Ƭѡ����
            else                                assert(0);//���Ŵ��� �������ʧ��
        }break;
        
        case SPI_4:
        {
            if      (SPI4_SCK_B18  == sck_pin)  iomuxc_pinconf(B18,ALT2,LPSPI_PIN_CONF);
            else if (SPI4_SCK_D0   == sck_pin)  iomuxc_pinconf(D0 ,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
            
            if      (SPI4_MOSI_B20 == mosi_pin) iomuxc_pinconf(B20,ALT2,LPSPI_PIN_CONF);
            else if (SPI4_MOSI_D2  == mosi_pin) iomuxc_pinconf(D2 ,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
                                                               
            if      (SPI4_MISO_B21 == miso_pin) iomuxc_pinconf(B21,ALT2,LPSPI_PIN_CONF);
            else if (SPI4_MISO_D3  == miso_pin) iomuxc_pinconf(D3 ,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//���Ŵ��� �������ʧ��
            
            if      (SPI4_CS0_B19  == cs_pin)   iomuxc_pinconf(B19,ALT2,LPSPI_PIN_CONF);
            else if (SPI4_CS0_D1   == cs_pin)   iomuxc_pinconf(D1 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI4_CS1_D4   == cs_pin)   iomuxc_pinconf(D4 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI4_CS2_D5   == cs_pin)   iomuxc_pinconf(D5 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI4_CS3_D6   == cs_pin)   iomuxc_pinconf(D6 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI_CS_NOT_USE  == cs_pin)   ;//��ʹ��Ƭѡ����
            else                                assert(0);//���Ŵ��� �������ʧ��
        }break;
        
        default:assert(0);break;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      SPI��ʼ��
//  @param      spi_n           ѡ��SPIģ��(SPI_1-SPI_4)
//  @param      cs_pin          ѡ��SPIƬѡ����
//  @param      sck_pin         ѡ��SPIʱ������
//  @param      mosi_pin        ѡ��SPI MOSI����
//  @param      miso_pin        ѡ��SPI MISO����
//  @param      mode            SPIģʽ 0��CPOL=0 CPHA=0    1��CPOL=0 CPHA=1   2��CPOL=1 CPHA=0   3��CPOL=1 CPHA=1 //����ϸ�ڿ����аٶ�
//  @param      baud            ����SPI�Ĳ�����
//  @return     void
//  Sample usage:               spi_init(SPI_1, SPI1_SCK_B10, SPI1_MOSI_B12, SPI1_MISO_B13, SPI1_CS0_B11, 1*1000*1000);//Ӳ��SPI��ʼ��     
//-------------------------------------------------------------------------------------------------------------------
void spi_init(SPIN_enum spi_n, SPI_PIN_enum sck_pin, SPI_PIN_enum mosi_pin, SPI_PIN_enum miso_pin, SPI_PIN_enum cs_pin, uint8 mode, uint32 baud)
{
    lpspi_master_config_t masterConfig;
    uint32 src_clock;
    
    spi_iomuxc(spi_n, sck_pin, mosi_pin, miso_pin, cs_pin);

    CLOCK_SetMux(kCLOCK_LpspiMux, LPSPI_CLK_SRC);    //ѡ��PLL2��ΪLPSPIʱ��Դ
    CLOCK_SetDiv(kCLOCK_LpspiDiv, LPSPI_CLK_DIV);
    
    LPSPI_MasterGetDefaultConfig(&masterConfig);

    masterConfig.baudRate = baud;
    masterConfig.bitsPerFrame = 8;
    masterConfig.whichPcs = (lpspi_which_pcs_t)(cs_pin%21/3-3);
    
    switch(mode)
    {
        case 0:
        {
            masterConfig.cpol = kLPSPI_ClockPolarityActiveHigh; 
            masterConfig.cpha = kLPSPI_ClockPhaseFirstEdge; 
        }break;
        
        case 1:
        {
            masterConfig.cpol = kLPSPI_ClockPolarityActiveHigh; 
            masterConfig.cpha = kLPSPI_ClockPhaseSecondEdge; 
        }break;
        
        case 2:
        {
            masterConfig.cpol = kLPSPI_ClockPolarityActiveLow; 
            masterConfig.cpha = kLPSPI_ClockPhaseFirstEdge; 
        }break;
        
        case 3:
        {
            masterConfig.cpol = kLPSPI_ClockPolarityActiveLow; 
            masterConfig.cpha = kLPSPI_ClockPhaseSecondEdge; 
        }break;
    }

    masterConfig.pcsToSckDelayInNanoSec = 1000000000 / masterConfig.baudRate;
    masterConfig.lastSckToPcsDelayInNanoSec = 1000000000 / masterConfig.baudRate;
    masterConfig.betweenTransferDelayInNanoSec = 1000000000 / masterConfig.baudRate;
    src_clock = (CLOCK_GetFreq(kCLOCK_SysPllClk) / (LPSPI_CLK_DIV + 1U));
    
    LPSPI_MasterInit(SPIN[spi_n], &masterConfig, src_clock);//��һ�γ�ʼ�����ڴ�ʱ��
    LPSPI_Reset(SPIN[spi_n]);                               //��λ����
    LPSPI_MasterInit(SPIN[spi_n], &masterConfig, src_clock);//���³�ʼ��������ȷ�Ĳ���
    
    LPSPI_Enable(SPIN[spi_n], false);
    SPIN[spi_n]->CFGR1 &= (~LPSPI_CFGR1_NOSTALL_MASK);
    LPSPI_Enable(SPIN[spi_n], true);

    LPSPI_FlushFifo(SPIN[spi_n], true, true);                       //ˢ��FIFO
    LPSPI_ClearStatusFlags(SPIN[spi_n], kLPSPI_AllStatusFlag);      //���״̬��־
    LPSPI_DisableInterrupts(SPIN[spi_n], kLPSPI_AllInterruptEnable);//�ر��ж�
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      SPI���ͽ��պ���
//  @param      spi_n           ѡ��SPIģ��   (SPI_1-SPI_4)
//  @param      cs_pin          ѡ��SPIƬѡ����
//  @param      modata          ���͵����ݻ�������ַ
//  @param      midata          ��������ʱ���յ������ݵĴ洢��ַ(����Ҫ������ NULL)
//  @param      len             ���͵��ֽ���
//  @param      continuous      ����ͨ����CS�Ƿ����������Ч״̬ 1:��������  0:ÿ������һ���ֽڹر�CS(һ������Ϊ1 ����)
//  @return     void				
//  @since      v2.0
//  Sample usage:       		spi_mosi(SPI_1,SPI1_CS0_A13,buf,buf,1);    //����buff�����ݣ������յ�buf�����Ϊ1�ֽ�
//-------------------------------------------------------------------------------------------------------------------
void spi_mosi(SPIN_enum spi_n, SPI_PIN_enum cs_pin, uint8 *modata, uint8 *midata, uint32 len, uint8 continuous)
{
    lpspi_transfer_t transfer;

    assert(0 != len);               //�����ֽ�����Ϊ0
    
    if(continuous)  transfer.configFlags = ((cs_pin%21/3-3)<<LPSPI_MASTER_PCS_SHIFT) | kLPSPI_MasterPcsContinuous;
    else            transfer.configFlags = ((cs_pin%21/3-3)<<LPSPI_MASTER_PCS_SHIFT);
    transfer.txData = modata;
    transfer.rxData = midata;
    transfer.dataSize = len;
    LPSPI_MasterTransferBlocking(SPIN[spi_n], &transfer);
}



