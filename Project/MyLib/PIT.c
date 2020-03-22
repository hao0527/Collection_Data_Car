#include "headfile.h"

void PIT_allocation_init()                  //配置中断服务函数   
{   
    pit_init();                             //周期定时器模块初始化
    
    pit_interrupt_ms(PIT_CH0,10);           //初始化pit通道0 周期10ms
    pit_interrupt_ms(PIT_CH1,5);
    pit_interrupt_ms(PIT_CH2,3);
//    pit_interrupt_ms(PIT_CH3,500);
}

void PIT_IRQHandler(void)
{
    if(PIT_FLAG_GET(PIT_CH0))
    {
        PIT_FLAG_CLEAR(PIT_CH0);
        //中断函数
    }
    
    if(PIT_FLAG_GET(PIT_CH1))
    {
        PIT_FLAG_CLEAR(PIT_CH1);
        Get_ADC();                          //获取电感值
        ADC_Compare();                      //计算diff与Normalization
    }
    
    if(PIT_FLAG_GET(PIT_CH2))
    {
        PIT_FLAG_CLEAR(PIT_CH2);
        //中断函数
    }
    
//    if(PIT_FLAG_GET(PIT_CH3))
//    {
//        PIT_FLAG_CLEAR(PIT_CH3);
//        //中断函数
//    }
    
    __DSB();
}
