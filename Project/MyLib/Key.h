#ifndef __Key_H__
#define __Key_H__

#include "common.h"

#define AJ1IO C15                   //�궨��IO�ܽ�����
#define AJ2IO C14
#define AJ3IO C13
#define BM1IO C8
#define BM2IO C9
#define BM3IO C10
#define BM4IO C11

extern int AJ1,AJ2,AJ3;         //��������
extern int BM1,BM2,BM3,BM4;         //���뿪������
extern int OLED_Flag;
void Key_allocation_init();
void KeyScan();

#endif
