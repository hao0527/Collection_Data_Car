#include "headfile.h"

int SPEED_DianJi_L, SPEED_DianJi_R, Speed_Mode=0;                               //ȫ�ֱ���

void BMQ_allocation_init()                                                      //��ʼ��������
{
    qtimer_quad_init(QTIMER_1, QTIMER1_TIMER0_D0, QTIMER1_TIMER1_D1);           //L
    qtimer_quad_init(QTIMER_1, QTIMER1_TIMER0_D0, QTIMER1_TIMER1_D1);           //R
}

void Get_Speed()
{
    SPEED_DianJi_L = qtimer_quad_get(QTIMER_1, QTIMER1_TIMER0_D0);              //������ȡ
    SPEED_DianJi_R = qtimer_quad_get(QTIMER_1, QTIMER1_TIMER0_D0);
    qtimer_quad_clear(QTIMER_1, QTIMER1_TIMER0_D0);
    qtimer_quad_clear(QTIMER_1, QTIMER1_TIMER0_D0);                             //��������
}

//int Get_Speed_aim(int flag)           //�µķŵ�MPU6050.c����
//{
//    int Speed_aim = 0;        //�ֲ�����
//    switch (Speed_Mode)
//    {
//        case 0:
//        {
//            switch (flag)
//            {
//                case 0:Speed_aim =4000;   break; //ֱ�����֣� �����ã�
//                case 1:Speed_aim =3700;   break; //ֱ�������� �����ã�
//                case 2:Speed_aim =3300;   break; //����     �����ã�
//                case 3:Speed_aim =3000;   break; //���    �����ã�
//                case 4:Speed_aim =2500;   break; // Բ����   �����ã�
//                case 5:Speed_aim =3000;   break; //ʮ��·��  �����ã�
//                case 6:Speed_aim =2000;   break; //����      �����ã�
//                case 7:Speed_aim =1800;   break; //ֱ���      �����ã�
//                case 8:Speed_aim =0;      break; //ͣ��
//                case 9:Speed_aim =500;    break; //���ϼ���   �����ã�
//                case 10:Speed_aim =2300;  break; //��Բ������   �����ã�
//                case 11:Speed_aim =2300;  break; //Բ�����   �����ã�
//                case 12:Speed_aim =2000;  break; //��Բ������   �����ã�
//                default:Speed_aim =0;
//            }
//            return Speed_aim;
//        }
//        break;

//        case 1:
//        {
//            switch (flag)
//            {
//                case 0:Speed_aim =4000;   break; //ֱ�����֣� �����ã�
//                case 1:Speed_aim =4300;   break; //ֱ�������� �����ã�
//                case 2:Speed_aim =3000;   break; //����     �����ã�
//                case 3:Speed_aim =2800;   break; //���    �����ã�
//                case 4:Speed_aim =3300;   break; // Բ����   �����ã�
//                case 5:Speed_aim =4000;   break; //ʮ��·��  �����ã�
//                case 6:Speed_aim =2300;   break; //����      �����ã�
//                case 7:Speed_aim =2500;   break; //ֱ���      �����ã�
//                case 8:Speed_aim =0;      break; //ͣ��
//                case 9:Speed_aim =0;      break; //���ϼ���   �����ã�
//                case 10:Speed_aim =3000;  break; //��Բ������   �����ã�
//                case 11:Speed_aim =3000;  break; //Բ�����   �����ã�
//                case 12:Speed_aim =3000;  break; //��Բ������   �����ã�
//                default:Speed_aim =0;
//            }
//            return Speed_aim;
//        }
//        break;
//    }
//    return -1;
//}


