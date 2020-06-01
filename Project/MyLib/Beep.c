#include "headfile.h"
#define BeepIO C12                                      //宏定义蜂鸣器IO口

void BEEP_Init()
{
    gpio_init(BeepIO, GPO, 0, GPIO_PIN_CONFIG);         //初始化GPIO
}

void bebebe()
{
    gpio_set(BeepIO, 1);
    pit_delay_ms(PIT_CH3,50);
    gpio_set(BeepIO, 0);
    pit_delay_ms(PIT_CH3,50);
    gpio_set(BeepIO, 1);
    pit_delay_ms(PIT_CH3,50);
    gpio_set(BeepIO, 0);
    pit_delay_ms(PIT_CH3,50);
    gpio_set(BeepIO, 1);
    pit_delay_ms(PIT_CH3,50);
    gpio_set(BeepIO, 0);
}

void bebe()
{
    gpio_set(BeepIO, 1);
    pit_delay_ms(PIT_CH3,50);
    gpio_set(BeepIO, 0);
    pit_delay_ms(PIT_CH3,50);
    gpio_set(BeepIO, 1);
    pit_delay_ms(PIT_CH3,50);
    gpio_set(BeepIO, 0);
}

void be()
{
    gpio_set(BeepIO, 1);
    pit_delay_ms(PIT_CH3,50);
    gpio_set(BeepIO, 0);
}

void beeee()
{
    gpio_set(BeepIO, 1);
    pit_delay_ms(PIT_CH3,100);
    gpio_set(BeepIO, 0);
}
