#include "headfile.h"
//在Key.h内宏定义IO管脚

int AJ1,AJ2,AJ3;         //全局变量    按键
int BM1,BM2,BM3,BM4;         //全局变量    拨码开关
int OLED_Flag;

void Key_allocation_init()
{
    //按键
    gpio_init (AJ1IO, GPI, 1, GPIO_PIN_CONFIG);                         //初始化  管脚为输入        AJ1        
    gpio_init (AJ2IO, GPI, 1, GPIO_PIN_CONFIG);                         //初始化  管脚为输入        AJ2              
    gpio_init (AJ3IO, GPI, 1, GPIO_PIN_CONFIG);                         //初始化  管脚为输入        AJ3                    

    //拨码开关
    gpio_init (BM1IO, GPI, 0, GPIO_PIN_CONFIG);                         //初始化  管脚为输入        BM4 
    gpio_init (BM2IO, GPI, 0, GPIO_PIN_CONFIG);                         //初始化  管脚为输入        BM3
    gpio_init (BM3IO, GPI, 0, GPIO_PIN_CONFIG);                         //初始化  管脚为输入        BM2
    gpio_init (BM4IO, GPI, 0, GPIO_PIN_CONFIG);                         //初始化  管脚为输入        BM1

//    gpio_init (C15, GPO, 0, GPIO_PIN_CONFIG);
}

void KeyScan()
{
    AJ1=0;AJ2=0;AJ3=0;            //按键清零
    BM1=0;BM2=0;BM3=0;BM4=0;            //拨码开关清零
    
    //按键
    if(gpio_get(AJ1IO)==0)  AJ1 = 1;
    if(gpio_get(AJ2IO)==0)  AJ2 = 1;
    if(gpio_get(AJ3IO)==0)  AJ3 = 1;
    //拨码开关
    if(gpio_get(BM1IO)==0)  BM4 = 1;
    if(gpio_get(BM2IO)==0)  BM3 = 1;
    if(gpio_get(BM3IO)==0)  BM2 = 1;
    if(gpio_get(BM4IO)==0)  BM1 = 1;
}

