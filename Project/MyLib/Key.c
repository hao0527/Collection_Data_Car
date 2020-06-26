#include "headfile.h"
//��Key.h�ں궨��IO�ܽ�

int AJ1,AJ2,AJ3;         //ȫ�ֱ���    ����
int BM1,BM2,BM3,BM4;         //ȫ�ֱ���    ���뿪��
int OLED_Flag;

void Key_allocation_init()
{
    //����
    gpio_init (AJ1IO, GPI, 1, GPIO_PIN_CONFIG);                         //��ʼ��  �ܽ�Ϊ����        AJ1        
    gpio_init (AJ2IO, GPI, 1, GPIO_PIN_CONFIG);                         //��ʼ��  �ܽ�Ϊ����        AJ2              
    gpio_init (AJ3IO, GPI, 1, GPIO_PIN_CONFIG);                         //��ʼ��  �ܽ�Ϊ����        AJ3                    

    //���뿪��
    gpio_init (BM1IO, GPI, 0, GPIO_PIN_CONFIG);                         //��ʼ��  �ܽ�Ϊ����        BM4 
    gpio_init (BM2IO, GPI, 0, GPIO_PIN_CONFIG);                         //��ʼ��  �ܽ�Ϊ����        BM3
    gpio_init (BM3IO, GPI, 0, GPIO_PIN_CONFIG);                         //��ʼ��  �ܽ�Ϊ����        BM2
    gpio_init (BM4IO, GPI, 0, GPIO_PIN_CONFIG);                         //��ʼ��  �ܽ�Ϊ����        BM1

//    gpio_init (C15, GPO, 0, GPIO_PIN_CONFIG);
}

void KeyScan()
{
    AJ1=0;AJ2=0;AJ3=0;            //��������
    BM1=0;BM2=0;BM3=0;BM4=0;            //���뿪������
    
    //����
    if(gpio_get(AJ1IO)==0)  AJ1 = 1;
    if(gpio_get(AJ2IO)==0)  AJ2 = 1;
    if(gpio_get(AJ3IO)==0)  AJ3 = 1;
    //���뿪��
    if(gpio_get(BM1IO)==0)  BM4 = 1;
    if(gpio_get(BM2IO)==0)  BM3 = 1;
    if(gpio_get(BM3IO)==0)  BM2 = 1;
    if(gpio_get(BM4IO)==0)  BM1 = 1;
}

