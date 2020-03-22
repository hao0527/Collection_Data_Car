#include "headfile.h"


void PIT_allocation_init() 					//配置中断服务函数   
{   
	pit_init();								//周期定时器模块初始化
	pit_interrupt_ms(PIT_CH0,100);  //初始化pit通道0 周期
    pit_interrupt_ms(PIT_CH1,300);  //初始化pit通道1 周期
    pit_interrupt_ms(PIT_CH2,600);  //初始化pit通道2 周期
    pit_interrupt_ms(PIT_CH3,900);  //初始化pit通道3 周期
	






    pit_init_ms(PIT0, 10);
    set_vector_handler(PIT0_VECTORn , PIT0_IRQHandler);   //设置LPTMR的中断服务函数为 PORTA_IRQHandler
    enable_irq(PIT0_IRQn);    
    
    pit_init_ms(PIT1, 5);
    set_vector_handler(PIT1_VECTORn , PIT1_IRQHandler);   //设置LPTMR的中断服务函数为 PORTA_IRQHandler
    enable_irq(PIT1_IRQn);    
    
    pit_init_ms(PIT2, 3);
    set_vector_handler(PIT2_VECTORn , PIT2_IRQHandler);   //设置LPTMR的中断服务函数为 PORTA_IRQHandler
    enable_irq(PIT2_IRQn);    
    
    NVIC_SetPriorityGrouping(4);     //设置优先级分组,4bit 抢占优先级,没有亚优先级
    NVIC_SetPriority(PIT0_IRQn,2);  
    NVIC_SetPriority(PIT1_IRQn,1); 
    NVIC_SetPriority(PIT2_IRQn,0); 
    
}  

void PIT0_IRQHandler()
{
/*
    if((GYH_AD[0] ==1)&&(GYH_AD[1] ==1)&&(GYH_AD[2] ==1)&&(GYH_AD[3] ==1))   //清中断标志位si[i]       
    {
        PIT_Flag_Clear(PIT0);
        return;
    }
*/
  
    //定时器中断服务程序写这下面
    led_turn(LED0);

    Get_Speed();                //获取编码器值
    PUTOUT_PWM();               //输出PWM波
    
    PIT_Flag_Clear(PIT0);       //清中断标志位si[i]

}


void PIT1_IRQHandler()
{
  
    //定时器中断服务程序写这下面
    led_turn(LED1);

    Get_ADC();                  //获取电感值
    ADC_Compare();              //计算diff与Normalization
    GET_PWM();                  //通过控制算法得到PWM值
    
    PIT_Flag_Clear(PIT1);       //清中断标志位si[i]

}


void PIT2_IRQHandler()
{
    //定时器中断服务程序写这下面
    led_turn(LED2);

    KeyScan();                  //按键赋值
    if(S4==1) Get_Basis_DG();   //得到电磁传感器数据 、设置初始值

    PIT_Flag_Clear(PIT2);       //清中断标志位si[i]

}


