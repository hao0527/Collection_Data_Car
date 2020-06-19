#include "headfile.h"

void oled_show()
{
    if(OLED_Flag==0)
    {
        oled_p6x8str(0,0,"vx:");
        oled_printf_int32(20,0,vx,3);
        oled_p6x8str(64,0,"vy:");
        oled_printf_int32(84,0,vy,3);
        oled_p6x8str(0,2,"pwmy:");
        oled_printf_int32(40,2,PWM_DianJi_L,5);
        oled_p6x8str(0,4,"pwmx:");
        oled_printf_int32(40,4,PWM_DuoJi,4);
    }
}
