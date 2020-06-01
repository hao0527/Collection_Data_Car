/*********************************************************************************************************************
 * @Project         Collection_Data_Car
 * @Version         通过传统控制采集电感值与舵机PWM
 * @Software        MDK 5.28
 * @Core            NXP RT1021DAG5A
 * @Date            2020-03-25
 * @Encoding        GB2312
 * @TabSize         4 Spaces
 * @GitHub          https://github.com/hao0527/Collection_Data_Car
 ********************************************************************************************************************/


#include "headfile.h"

uint8 send_buff[11];		        //无线转串口发送数组

void main(void)
{
    DisableGlobalIRQ();
    board_init();                   //务必保留，本函数用于初始化MPU 时钟 调试串口
    
    BEEP_Init();                    //蜂鸣器初始化
    Key_allocation_init();          //按键拨码器初始化
//    mpu6050_self2_check();          //MPU6050自检函数
//    mpu6050_init_hardware();        //MPU6050初始化
    DG_ADC_Init();                  //电感ADC初始化
    PWM_allocation_init();          //配置PWM输出管脚
    BMQ_allocation_init();          //编码器初始化
//    seekfree_wireless_init();       //初始化无线转串口模块
    
    PIT_allocation_init();          //配置中断服务函数
    EnableGlobalIRQ(0);             //总中断最后开启
    
    while(1)
    {
//        //数据发送代码建议放在主循环，使用if查询，如果数据采集成功就发送数据
//		if(collection_succes)
//        {
//			collection_succes = 0;
//
//			//前两个字节为时间，如果程序结构里面有时间变量可以将时间变量输出，这样我们接受到数据后
//			//可以根据时间来判断包是否是连续的，是否有丢包
//            send_buff[0] = 0;
//            send_buff[1] = 0;
//
//            send_buff[2] = X1;
//            send_buff[3] = X2;
//            send_buff[4] = X3;
//            send_buff[5] = X4;
//            send_buff[6] = X5;
//            send_buff[7] = X6;
//            send_buff[8] = X7;
//
//			//将舵机数值转换为-128至+127  因为舵机转角被限制在-400至+400之间，
//			//因此舵机转角除以420之后绝对值必定是小于1的，
//			//然后在乘以128数据范围也就一定被限制在了-128至+127之间了。
//            send_buff[9] = (int32)(PWM_DuoJi-DuoJi_Mid)*128/420;
//
//			//固定字节，可以用于校验或者方便肉眼可辨每一个包是否正确
//            send_buff[10] = 0x5a;
//
//            seekfree_wireless_send_buff(send_buff,11);      //到时候先用蓝牙试试会不会丢包
//        }
    }
}
