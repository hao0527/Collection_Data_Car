#include "headfile.h"
//��Key.h�ں궨��IO�ܽ�

int AJ1,AJ2,AJ3,AJ4;         //ȫ�ֱ���    ����
int BM1,BM2,BM3,BM4;         //ȫ�ֱ���    ���뿪��
int OLED_Flag;

void Key_allocation_init()
{
    //����
    gpio_init (AJ1IO, GPI, 1, GPIO_PIN_CONFIG);                         //��ʼ�� E8  �ܽ�Ϊ����        AJ1        
    gpio_init (AJ2IO, GPI, 1, GPIO_PIN_CONFIG);                         //��ʼ�� E9  �ܽ�Ϊ����        AJ2              
    gpio_init (AJ3IO, GPI, 1, GPIO_PIN_CONFIG);                         //��ʼ�� E10 �ܽ�Ϊ����        AJ3              
    gpio_init (AJ4IO, GPI, 1, GPIO_PIN_CONFIG);                         //��ʼ�� E11 �ܽ�Ϊ����        AJ4              
    
    //���뿪��
    gpio_init (BM1IO, GPI, 0, GPIO_PIN_CONFIG);                         //��ʼ�� E4  �ܽ�Ϊ����        BM4 
    gpio_init (BM2IO, GPI, 0, GPIO_PIN_CONFIG);                         //��ʼ�� E5  �ܽ�Ϊ����        BM3
    gpio_init (BM3IO, GPI, 0, GPIO_PIN_CONFIG);                         //��ʼ�� E6  �ܽ�Ϊ����        BM2
    gpio_init (BM4IO, GPI, 0, GPIO_PIN_CONFIG);                         //��ʼ�� E7  �ܽ�Ϊ����        BM1
}

void KeyScan()
{
    AJ1=0;AJ2=0;AJ3=0;AJ4=0;            //��������
    BM1=0;BM2=0;BM3=0;BM4=0;            //���뿪������
    
    //����
    if(gpio_get(AJ1IO)==0)  AJ1 = 1;
    if(gpio_get(AJ2IO)==0)  AJ2 = 1;
    if(gpio_get(AJ3IO)==0)  AJ3 = 1;
    if(gpio_get(AJ4IO)==0)  AJ4 = 1;
    //���뿪��
    if(gpio_get(BM1IO)==0)  BM4 = 1;
    if(gpio_get(BM1IO)==0)  BM3 = 1;
    if(gpio_get(BM1IO)==0)  BM2 = 1;
    if(gpio_get(BM1IO)==0)  BM1 = 1;
}

