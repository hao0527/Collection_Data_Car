#include "headfile.h"

//�ܽź궨�������ȫ�ֱ�����SEEKFREE_MPU6050.c
//����������ȫ�ֱ��� mpu_gyro_x,mpu_gyro_y,mpu_gyro_z;
//����������ȫ�ֱ��� mpu_acc_x,mpu_acc_y,mpu_acc_z;
//ͨ�������ǿ��Ƴ��٣�ת����ʱ�򽵵��ٶ�

int Speed_aim_max, Speed_aim_min;                           //���ٷ�Χ
int Speed_aim;                                              //ȫ�ֱ���

void Get_Speed_aim()
{
    get_accdata_hardware();                                 //��ȡ�����Ǽ��ٶ�����
//    get_gyro_hardware();                                    //��ȡ��������������
    if(mpu_acc_y<500) Speed_aim=5000;
    else if(mpu_acc_y<1000) Speed_aim=4000;
    else if(mpu_acc_y<2000) Speed_aim=3000;
    else Speed_aim=2000;
    
//    Speed_aim=5000-mpu_acc_y*1;                             //ʹ��Ŀ���ٶȺ�y����ٵĹ�ϵʽ��ȷ�����ٶ�
}

//��ô��һҳֻ��һ��������  �ǵġ�