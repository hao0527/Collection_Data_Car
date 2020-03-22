/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		IPS 2.0��Һ��
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-09-17
 * @note		
					���߶��壺
					------------------------------------ 
						ģ��ܽ�            ��Ƭ���ܽ�
						D0                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_D0_PIN  �궨��
						D1                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_D1_PIN  �궨��
						D2                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_D2_PIN  �궨��
						D3                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_D3_PIN  �궨��
						D4                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_D4_PIN  �궨��
						D5                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_D5_PIN  �궨��
						D6                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_D6_PIN  �궨��
						D7                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_D7_PIN  �궨��
                                                              _                           
						BL                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_BL_PIN  �궨��
						CS                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_CS_PIN  �궨��
						RD                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_RD_PIN  �궨��
						WR                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_WR_PIN  �궨��
						RS                 �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_RS_PIN  �궨��
						RST                �鿴SEEKFREE_IPS200_PARALLEL8.H�ļ��ڵ�IPS200_RST_PIN �궨��

						��Դ����
						VCC 3.3V��Դ
						GND ��Դ��
						���ֱ���240*320
					------------------------------------ 

 ********************************************************************************************************************/



#ifndef _SEEKFREE_IPS200_PARALLEL8_H
#define _SEEKFREE_IPS200_PARALLEL8_H

#include "common.h"


//--------------���Ŷ���--------------
//8���������ű������� ����C0-C7,C6-C13�ȵȡ�
#define IPS200_D0_PIN           C2
#define IPS200_D1_PIN           C3
#define IPS200_D2_PIN           C4
#define IPS200_D3_PIN           C5
#define IPS200_D4_PIN           C6
#define IPS200_D5_PIN           C7
#define IPS200_D6_PIN           C8
#define IPS200_D7_PIN           C9

//��������
#define IPS200_RD_PIN           B31
#define IPS200_WR_PIN           B29
#define IPS200_RS_PIN           B27
#define IPS200_RST_PIN          B25
#define IPS200_CS_PIN           B23
#define IPS200_BL_PIN           B21

#define IPS200_BL(x)            gpio_set(IPS200_BL_PIN,x)
#define IPS200_CS(x)            gpio_set(IPS200_CS_PIN,x)
#define IPS200_RD(x)            gpio_set(IPS200_RD_PIN,x)
#define IPS200_WR(x)            gpio_set(IPS200_WR_PIN,x)
#define IPS200_RS(x)            gpio_set(IPS200_RS_PIN,x)
#define IPS200_RST(x)           gpio_set(IPS200_RST_PIN,x)


//�������ݶ˿�����PORT���л����ź���ظ�����������PORT���и���
//Ĭ����������ʹ�õ���C�˿ڣ��������Ĭ������Ϊ2
#define IPS200_DATA_PORT        2       //1��B�˿�  2��C�˿�  3��D�˿�

#if  ( 1 == IPS200_DATA_PORT )
    #define IPS200_DATAPORT     PORTB_DR	    //�궨��GPIO������Ĵ���
#elif( 2 == IPS200_DATA_PORT )
    #define IPS200_DATAPORT     PORTC_DR	    //�궨��GPIO������Ĵ���
#elif( 3 == IPS200_DATA_PORT )
    #define IPS200_DATAPORT     PORTD_DR	    //�궨��GPIO������Ĵ���
#endif

#define DATA_START_NUM		    (IPS200_D0_PIN&0x1f)  //�궨���������ŵ���ʼ���





//-------������ɫ��SEEKFREE_FONT.h�ļ��ж���----------
//#define RED          			0xF800	//��ɫ
//#define BLUE         			0x001F  //��ɫ
//#define YELLOW       			0xFFE0	//��ɫ
//#define GREEN        			0x07E0	//��ɫ
//#define WHITE        			0xFFFF	//��ɫ
//#define BLACK        			0x0000	//��ɫ 
//#define GRAY  				0X8430 	//��ɫ
//#define BROWN 				0XBC40 	//��ɫ
//#define PURPLE    			0XF81F	//��ɫ
//#define PINK    				0xED31	//�ۺ�ɫ

//����д�ֱʵ���ɫ
#define IPS200_PENCOLOR         RED

//���屳����ɫ
#define IPS200_BGCOLOR          WHITE

#define IPS200_W 				240	    	
#define IPS200_H 				320	    	




//--------------������ʾ����--------------
//0 ����ģʽ
//1 ����ģʽ  ��ת180��
//2 ����ģʽ
//3 ����ģʽ  ��ת180��
#define IPS200_DISPLAY_DIR 0

#if   (0==IPS200_DISPLAY_DIR || 1==IPS200_DISPLAY_DIR)
#define	IPS200_X_MAX			IPS200_W	//Һ��X�����
#define IPS200_Y_MAX			IPS200_H   //Һ��Y�����
     
#elif (2==IPS200_DISPLAY_DIR || 3==IPS200_DISPLAY_DIR)
#define	IPS200_X_MAX			IPS200_H	//Һ��X�����
#define IPS200_Y_MAX			IPS200_W   //Һ��Y�����
     
#else
#error "IPS200_DISPLAY_DIR �������"
     
#endif


void ips200_init(void); //��ʼ��Ӳ��
void ips200_w_data(uint8 dat);
void ips200_wr_reg(uint16 com);
void ips200_wr_data(uint8 dat);
void ips200_wr_data16(uint16 dat);
void ips200_w_reg(uint8 com,uint8 dat);
void ips200_address_set(uint16 x1,uint16 y1,uint16 x2,uint16 y2);
void ips200_clear(uint16 Color);
void ips200_drawpoint(uint16 x,uint16 y,uint16 color);
void ips200_showchar(uint16 x,uint16 y,const int8 dat);
void ips200_showstr(uint16 x,uint16 y,const int8 dat[]);

void ips200_showint8(uint16 x,uint16 y,int8 dat);
void ips200_showuint8(uint16 x,uint16 y,uint8 dat);
void ips200_showint16(uint16 x,uint16 y,int16 dat);
void ips200_showuint16(uint16 x,uint16 y,uint16 dat);
void ips200_showint32(uint16 x,uint16 y,int dat,uint8 num);
void ips200_showfloat(uint16 x,uint16 y,double dat,int8 num,int8 pointnum);
void ips200_showimage(uint16 x,uint16 y,uint16 w,uint16 l,const unsigned char *p);
void ips200_display_chinese(uint16 x, uint16 y, uint8 size, const uint8 *p, uint8 number, uint16 color);

void ips200_displayimage032(uint8 *p, uint16 width, uint16 height);
void ips200_displayimage032_zoom(uint8 *p, uint16 width, uint16 height, uint16 dis_width, uint16 dis_height);
void ips200_displayimage032_zoom1(uint8 *p, uint16 width, uint16 height, uint16 start_x, uint16 start_y, uint16 dis_width, uint16 dis_height);
void ips200_displayimage7725(uint8 *p, uint16 width, uint16 height);
void ips200_displayimage8660_zoom(uint16 *p, uint16 width, uint16 height, uint16 dis_width, uint16 dis_height);


#endif

