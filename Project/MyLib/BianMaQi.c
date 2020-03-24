#include "headfile.h"

int SPEED_DianJi_L, SPEED_DianJi_R, Speed_Mode=0;                               //全局变量

void BMQ_allocation_init()                                                      //初始化编码器
{
    qtimer_quad_init(QTIMER_1, QTIMER1_TIMER0_D0, QTIMER1_TIMER1_D1);           //L
    qtimer_quad_init(QTIMER_1, QTIMER1_TIMER0_D0, QTIMER1_TIMER1_D1);           //R
}

void Get_Speed()
{
    SPEED_DianJi_L = qtimer_quad_get(QTIMER_1, QTIMER1_TIMER0_D0);              //计数获取
    SPEED_DianJi_R = qtimer_quad_get(QTIMER_1, QTIMER1_TIMER0_D0);
    qtimer_quad_clear(QTIMER_1, QTIMER1_TIMER0_D0);
    qtimer_quad_clear(QTIMER_1, QTIMER1_TIMER0_D0);                             //计数清零
}

//int Get_Speed_aim(int flag)           //新的放到MPU6050.c里了
//{
//    int Speed_aim = 0;        //局部变量
//    switch (Speed_Mode)
//    {
//        case 0:
//        {
//            switch (flag)
//            {
//                case 0:Speed_aim =4000;   break; //直道（粗） （有用）
//                case 1:Speed_aim =3700;   break; //直道（精） （有用）
//                case 2:Speed_aim =3300;   break; //减速     （有用）
//                case 3:Speed_aim =3000;   break; //弯道    （有用）
//                case 4:Speed_aim =2500;   break; // 圆环内   （有用）
//                case 5:Speed_aim =3000;   break; //十字路口  （有用）
//                case 6:Speed_aim =2000;   break; //避障      （有用）
//                case 7:Speed_aim =1800;   break; //直弯道      （有用）
//                case 8:Speed_aim =0;      break; //停车
//                case 9:Speed_aim =500;    break; //避障减速   （有用）
//                case 10:Speed_aim =2300;  break; //进圆环减速   （有用）
//                case 11:Speed_aim =2300;  break; //圆环打角   （有用）
//                case 12:Speed_aim =2000;  break; //出圆环减速   （有用）
//                default:Speed_aim =0;
//            }
//            return Speed_aim;
//        }
//        break;

//        case 1:
//        {
//            switch (flag)
//            {
//                case 0:Speed_aim =4000;   break; //直道（粗） （有用）
//                case 1:Speed_aim =4300;   break; //直道（精） （有用）
//                case 2:Speed_aim =3000;   break; //减速     （有用）
//                case 3:Speed_aim =2800;   break; //弯道    （有用）
//                case 4:Speed_aim =3300;   break; // 圆环内   （有用）
//                case 5:Speed_aim =4000;   break; //十字路口  （有用）
//                case 6:Speed_aim =2300;   break; //避障      （有用）
//                case 7:Speed_aim =2500;   break; //直弯道      （有用）
//                case 8:Speed_aim =0;      break; //停车
//                case 9:Speed_aim =0;      break; //避障减速   （有用）
//                case 10:Speed_aim =3000;  break; //进圆环减速   （有用）
//                case 11:Speed_aim =3000;  break; //圆环打角   （有用）
//                case 12:Speed_aim =3000;  break; //出圆环减速   （有用）
//                default:Speed_aim =0;
//            }
//            return Speed_aim;
//        }
//        break;
//    }
//    return -1;
//}


