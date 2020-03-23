#ifndef __Key_H__
#define __Key_H__

#define AJ1IO D14                   //宏定义IO管脚设置
#define AJ2IO D14
#define AJ3IO D14
#define AJ4IO D14
#define BM1IO D14
#define BM2IO D14
#define BM3IO D14
#define BM4IO D14

extern int AJ1,AJ2,AJ3,AJ4;         //按键清零
extern int BM1,BM2,BM3,BM4;         //拨码开关清零
extern int OLED_Flag;
void Key_allocation_init();
void KeyScan();

#endif
