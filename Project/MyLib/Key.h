#ifndef __Key_H__
#define __Key_H__

#define AJ1IO D14                   //�궨��IO�ܽ�����
#define AJ2IO D14
#define AJ3IO D14
#define AJ4IO D14
#define BM1IO D14
#define BM2IO D14
#define BM3IO D14
#define BM4IO D14

extern int AJ1,AJ2,AJ3,AJ4;         //��������
extern int BM1,BM2,BM3,BM4;         //���뿪������
extern int OLED_Flag;
void Key_allocation_init();
void KeyScan();

#endif
