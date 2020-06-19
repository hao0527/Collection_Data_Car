#include "headfile.h"

void PIT_allocation_init()                  //配置中断服务函数   
{   
    pit_init();                             //周期定时器模块初始化
    
    pit_interrupt_ms(PIT_CH0,10);           //初始化pit通道0 周期10ms
    pit_interrupt_ms(PIT_CH1,5);
    pit_interrupt_ms(PIT_CH2,50);
//    pit_interrupt_ms(PIT_CH3,500);
}

void PIT_IRQHandler(void)
{
    if(PIT_FLAG_GET(PIT_CH0))
    {
        PIT_FLAG_CLEAR(PIT_CH0);
        PUTOUT_PWM();                       //输出PWM波
    }
    
    if(PIT_FLAG_GET(PIT_CH1))
    {
        PIT_FLAG_CLEAR(PIT_CH1);
        Get_ADC();                          //采集5个前瞻电感值
        ADC_Compare();                      //计算diff与Normalization
        Get_Speed();                        //读取编码器
        GET_PWM();                          //控制算法计算PWM
        ad_collection();                    //采集7个电感值
    }
    
    if(PIT_FLAG_GET(PIT_CH2))
    {
        PIT_FLAG_CLEAR(PIT_CH2);
        KeyScan();                          //按键赋值
//				if(AJ1==1) {PWM_DuoJi+=10;  PRINTF("%d\n",PWM_DuoJi);}
//				if(AJ2==1) {PWM_DuoJi-=10;  PRINTF("%d\n",PWM_DuoJi);}
//				if(AJ3==1) PRINTF("3");

//				if(BM1==1) PRINTF("1");
//				if(BM2==1) PRINTF("2");
//				if(BM3==1) PRINTF("3");
//				if(BM4==1) PRINTF("4");
        if(BM1==0&&BM2==0&&BM4==1&&BM4==1) {OLED_Flag=0;}
//        if(B1==0&&B2==1&&B4==1&&B4==1) OLED_Flag=1;
//        if(B1==1&&B2==0&&B4==1&&B4==1) 
//        {
//            OLED_Flag=2;
//            if(S4==1) Get_Basis_DG();       //得到电磁传感器数据 、设置初始值
//            if(S1==1) Clean_Basis_DG();     //清除Basis
//        }
//        if(B1==1&&B2==1&&B4==1&&B4==1) 
//        {
//            OLED_Flag=3;
//            if(S4==1) Save_DuoJi_Flash();
//            if(S3==1) {DuoJi_Mid=flash_read(108,0,uint16);if(DuoJi_Mid<DuoJi_Left) DuoJi_Mid=DuoJi_Left;if(DuoJi_Mid>DuoJi_Right) DuoJi_Mid=DuoJi_Right;}
//            if(S1==1) {DuoJi_Mid-=1;if(DuoJi_Mid<DuoJi_Left) DuoJi_Mid=DuoJi_Left;if(DuoJi_Mid>DuoJi_Right) DuoJi_Mid=DuoJi_Right;}
//            if(S2==1) {DuoJi_Mid+=1;if(DuoJi_Mid<DuoJi_Left) DuoJi_Mid=DuoJi_Left;if(DuoJi_Mid>DuoJi_Right) DuoJi_Mid=DuoJi_Right;}
//        }
//        if(B1==0&&B2==0&&B4==0&&B4==0) OLED_Flag=4;
        oled_show();
    }
    
//    if(PIT_FLAG_GET(PIT_CH3))
//    {
//        PIT_FLAG_CLEAR(PIT_CH3);
//        //中断函数
//    }
    
    __DSB();
}
