/*********************************************************************************************************************
 * @Project			Collection_Data_Car
 * @Version			通过传统控制采集电感值与舵机PWM
 * @Software 		MDK 5.28
 * @Core			NXP RT1021DAG5A
 * @Date       		2020-03-21
 * @TabSize			4
 ********************************************************************************************************************/


#include "headfile.h"


uint16 adc_value;
void main(void)
{
    DisableGlobalIRQ();
    board_init();                   //务必保留，本函数用于初始化MPU 时钟 调试串口
    DG_ADC_Init();                  //电感ADC初始化

    //此处编写用户代码(例如：外设初始化代码等)

    EnableGlobalIRQ(0);             //总中断最后开启
    while(1)
    {
        //此处编写需要循环执行的代码
    }
}
