#ifndef __Key_H__
#define __Key_H__

#include "common.h"

#define AJ1IO C15                   //宏定义IO管脚设置
#define AJ2IO C14
#define AJ3IO C13
#define BM1IO C8
#define BM2IO C9
#define BM3IO C10
#define BM4IO C11

extern int AJ1,AJ2,AJ3;         //按键清零
extern int BM1,BM2,BM3,BM4;         //拨码开关清零
extern int OLED_Flag;
void Key_allocation_init();
void KeyScan();

#endif
