#include "headfile.h"

/*********电感变量名**********
循迹电感    XL YL XM YR XR

采样电感    X1 X2 X3 X4 X5
            X6          X7
******************************/

float XL, YL, XM, YR, XR;                                                           //全局变量
uint16 X1, X2, X3, X4, X5, X6, X7;                                                  //全局变量
float diffX, diffY;                                                                 //全局变量
float NormalizationX, NormalizationY;                                               //全局变量
int Max_DG=303 , Min_DG=0;                                                          //电感上标定值，下标定值


void DG_ADC_Init()                                                                  //12个电感ADC初始化
{
    adc_init(ADC_2,ADC2_CH0_B13,ADC_8BIT);
    adc_init(ADC_1,ADC1_CH1_B14,ADC_8BIT);                                          //初始化ADC1模块的0通道(使用B12引脚) 分辨率为8位 
    adc_init(ADC_1,ADC1_CH2_B15,ADC_8BIT);
    adc_init(ADC_1,ADC1_CH3_B17,ADC_8BIT);
    adc_init(ADC_2,ADC2_CH3_B18,ADC_8BIT);
    adc_init(ADC_1,ADC1_CH4_B19,ADC_8BIT);
    adc_init(ADC_2,ADC2_CH4_B20,ADC_8BIT);
}

void Get_ADC()
{
    X1 = adc_mid_mean_filter1(ADC_2,ADC2_CH0_B13,12);
    X2 = adc_mid_mean_filter1(ADC_1,ADC1_CH1_B14,12);                               //ADC1模块的0通道(使用B12引脚)转换10次，返回中值平均值
    X3 = adc_mid_mean_filter1(ADC_1,ADC1_CH2_B15,12);
    X4 = adc_mid_mean_filter1(ADC_1,ADC1_CH3_B17,12);
    X5 = adc_mid_mean_filter1(ADC_2,ADC2_CH3_B18,12);
    X6 = adc_mid_mean_filter1(ADC_1,ADC1_CH4_B19,12);
    X7 = adc_mid_mean_filter1(ADC_2,ADC2_CH4_B20,12);                                  //这7个电感写到Collection.c里了

    X1 = ((X1 - Min_DG)/Max_DG) * 100.f;                                       //归一化   Value = ((Expression-Min)/Max)*100.0f
    X2 = ((X2 - Min_DG)/Max_DG) * 100.f;
    X3 = ((X3 - Min_DG)/Max_DG) * 100.f;
    X4 = ((X4 - Min_DG)/Max_DG) * 100.f;
    X5 = ((X5 - Min_DG)/Max_DG) * 100.f;
    X6 = ((X6 - Min_DG)/Max_DG) * 100.f;
    X7 = ((X7 - Min_DG)/Max_DG) * 100.f;

    X1 = X1 > 99.0f ? 99.0f : X1;                                        //归一化限幅
    X2 = X2 > 99.0f ? 99.0f : X2;
    X3 = X3 > 99.0f ? 99.0f : X3;
    X4 = X4 > 99.0f ? 99.0f : X4;
    X5 = X5 > 99.0f ? 99.0f : X5;
    X6 = X6 > 99.0f ? 99.0f : X6;
    X7 = X7 > 99.0f ? 99.0f : X7;

    X1 = X1 <5.0f ? 1.0f : X1;                                               //最小值限幅
    X2 = X2 <5.0f ? 1.0f : X2;
    X3 = X3 <5.0f ? 1.0f : X3;
    X4 = X4 <5.0f ? 1.0f : X4;
    X5 = X5 <5.0f ? 1.0f : X5;
    X6 = X6 <5.0f ? 1.0f : X6;
    X7 = X7 <5.0f ? 1.0f : X7;
}

void ADC_Compare()
{
    //差值
    diffX = XL - XR;    //  >0偏右    <0偏左    
    diffY = YL - YR;
    
    //差比和
    NormalizationX = ( (XL - XR) / (XL + XR) )*100;     //-100~100  >0偏右    <0偏左
    NormalizationY = ( (YL - YR) / (YL + YR) )*100;
}

//void Get_Basis_DG()
//{
//    Get_ADC();              //设置基础值（判断直道和弯道）
//    
//    if(Basis_YL1 < YL1) Basis_YL1 = YL1;
//    if(Basis_YR1 < YR1) Basis_YR1 = YR1;
//    if(Basis_X1 < X1) Basis_X1 = X1;
//    if(Basis_X2 < X2) Basis_X2 = X2;
//    if(Basis_XL1 < XL1) Basis_XL1 = XL1;
//    if(Basis_XR1 < XR1) Basis_XR1 = XR1;
//    if(Basis_XL2 < XL2) Basis_XL2 = XL2;
//    if(Basis_XR2 < XR2) Basis_XR2 = XR2;
//    
//    Save_Flash();           //保存到Flash
//}
