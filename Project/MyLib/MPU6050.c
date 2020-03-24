#include "headfile.h"

//管脚宏定义和数据全局变量在SEEKFREE_MPU6050.c
//陀螺仪数据全局变量 mpu_gyro_x,mpu_gyro_y,mpu_gyro_z;
//陀螺仪数据全局变量 mpu_acc_x,mpu_acc_y,mpu_acc_z;
//通过陀螺仪控制车速，转向大的时候降低速度

int Speed_aim_max, Speed_aim_min;                           //限速范围
int Speed_aim;                                              //全局变量

void Get_Speed_aim()
{
    get_accdata_hardware();                                 //获取陀螺仪加速度数据
//    get_gyro_hardware();                                    //获取陀螺仪坐标数据
    if(mpu_acc_y<500) Speed_aim=5000;
    else if(mpu_acc_y<1000) Speed_aim=4000;
    else if(mpu_acc_y<2000) Speed_aim=3000;
    else Speed_aim=2000;
    
//    Speed_aim=5000-mpu_acc_y*1;                             //使用目标速度和y轴加速的关系式精确控制速度
}

//这么大一页只有一个函数？  是的。