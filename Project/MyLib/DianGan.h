#ifndef __DianGan_H__
#define __DianGan_H__


extern float XL, YL, XM, YR, XR;                //ȫ�ֱ���
extern int X1, X2, X3, X4, X5, X6, X7;          //ȫ�ֱ���
extern float diffX, diffY;                      //ȫ�ֱ���
extern float NormalizationX, NormalizationY;    //ȫ�ֱ���


void DG_ADC_Init();
void Get_ADC();
void ADC_Compare();
//void Get_Basis_DG();

#endif