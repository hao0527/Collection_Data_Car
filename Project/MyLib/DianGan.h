#ifndef __DianGan_H__
#define __DianGan_H__

#include "common.h"

extern float XL, YL, XM, YR, XR;                //全局变量
extern uint16 X1, X2, X3, X4, X5, X6, X7;       //全局变量
extern float diffX, diffY;                      //全局变量
extern float NormalizationX, NormalizationY;    //全局变量


void DG_ADC_Init();
void Get_ADC();
void ADC_Compare();
//void Get_Basis_DG();

#endif