#include "headfile.h"



int vx,vy;

int uint8toint8(uint8 val)
{
    int intval;
    if(val>=128)intval=val-256;
    else intval=val;
    return intval;
}




//void receive_car_mode()
//{
//    
//}
