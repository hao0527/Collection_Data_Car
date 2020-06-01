#include "headfile.h"

/*********��б�����**********
ѭ�����    XL YL XM YR XR

�������    X1 X2 X3 X4 X5
            X6          X7
******************************/

float XL, YL, XM, YR, XR;                                                           //ȫ�ֱ���
uint16 X1, X2, X3, X4, X5, X6, X7;                                                  //ȫ�ֱ���
float diffX, diffY;                                                                 //ȫ�ֱ���
float NormalizationX, NormalizationY;                                               //ȫ�ֱ���
int Max_DG=303 , Min_DG=0;                                                          //����ϱ궨ֵ���±궨ֵ


void DG_ADC_Init()                                                                  //12�����ADC��ʼ��
{
    adc_init(ADC_1,ADC1_CH1_B14,ADC_8BIT);                                          //��ʼ��ADC1ģ���0ͨ��(ʹ��B12����) �ֱ���Ϊ8λ 
    adc_init(ADC_1,ADC1_CH2_B15,ADC_8BIT);
    adc_init(ADC_1,ADC1_CH3_B17,ADC_8BIT);
    adc_init(ADC_2,ADC2_CH3_B18,ADC_8BIT);
    adc_init(ADC_1,ADC1_CH4_B19,ADC_8BIT);
    adc_init(ADC_2,ADC2_CH5_B21,ADC_8BIT);
    adc_init(ADC_2,ADC2_CH6_B22,ADC_8BIT);
    adc_init(ADC_2,ADC2_CH7_B23,ADC_8BIT);
    adc_init(ADC_1,ADC1_CH8_B24,ADC_8BIT);
    adc_init(ADC_1,ADC1_CH9_B25,ADC_8BIT);
    adc_init(ADC_1,ADC1_CH10_B26,ADC_8BIT);
    adc_init(ADC_1,ADC1_CH11_B27,ADC_8BIT);
}

void Get_ADC()
{
    XL = adc_mid_mean_filter1(ADC_1,ADC1_CH1_B14,12);                               //ADC1ģ���0ͨ��(ʹ��B12����)ת��10�Σ�������ֵƽ��ֵ
    YL = adc_mid_mean_filter1(ADC_1,ADC1_CH2_B15,12);
    XM = adc_mid_mean_filter1(ADC_1,ADC1_CH3_B17,12);
    YR = adc_mid_mean_filter1(ADC_2,ADC2_CH3_B18,12);
    XR = adc_mid_mean_filter1(ADC_1,ADC1_CH4_B19,12);
//    X1 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);                                  //��7�����д��Collection.c����
//    X2 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
//    X3 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
//    X4 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
//    X5 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
//    X6 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
//    X7 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
    
    XL = ((XL - Min_DG)/Max_DG) * 100.f;                                            //��һ��   Value = ((Expression-Min)/Max)*100.0f
    YL = ((YL - Min_DG)/Max_DG) * 100.f;
    XM = ((XM - Min_DG)/Max_DG) * 100.f;
    YR = ((YR - Min_DG)/Max_DG) * 100.f;
    XR = ((XR - Min_DG)/Max_DG) * 100.f;
//    X1 = ((X1 - Min_DG)/Max_DG) * 100.f;
//    X2 = ((X2 - Min_DG)/Max_DG) * 100.f;
//    X3 = ((X3 - Min_DG)/Max_DG) * 100.f;
//    X4 = ((X4 - Min_DG)/Max_DG) * 100.f;
//    X5 = ((X5 - Min_DG)/Max_DG) * 100.f;
//    X6 = ((X6 - Min_DG)/Max_DG) * 100.f;
//    X7 = ((X7 - Min_DG)/Max_DG) * 100.f;
    
    XL = XL > 99.9f ? 99.9f : XL;                                                   //��һ���޷�
    YL = YL > 99.0f ? 99.0f : YL;
    XM = XM > 99.0f ? 99.0f : XM;
    YR = YR > 99.0f ? 99.0f : YR;
    XR = XR > 99.0f ? 99.0f : XR;
//    X1 = X1 > 99.0f ? 99.0f : X1;
//    X2 = X2 > 99.0f ? 99.0f : X2;
//    X3 = X3 > 99.0f ? 99.0f : X3;
//    X4 = X4 > 99.0f ? 99.0f : X4;
//    X5 = X5 > 99.0f ? 99.0f : X5;
//    X6 = X6 > 99.0f ? 99.0f : X6;
//    X7 = X7 > 99.0f ? 99.0f : X7;

    XL = XL <5.0f ? 1.0f : XL;                                                      //��Сֵ�޷�
    YL = YL <5.0f ? 1.0f : YL;
    XM = XM <5.0f ? 1.0f : XM;
    YR = YR <5.0f ? 1.0f : YR;
    XR = XR <5.0f ? 1.0f : XR;
//    X1 = X1 <5.0f ? 1.0f : X1;
//    X2 = X2 <5.0f ? 1.0f : X2;
//    X3 = X3 <5.0f ? 1.0f : X3;
//    X4 = X4 <5.0f ? 1.0f : X4;
//    X5 = X5 <5.0f ? 1.0f : X5;
//    X6 = X6 <5.0f ? 1.0f : X6;
//    X7 = X7 <5.0f ? 1.0f : X7;
}

void ADC_Compare()
{
    //��ֵ
    diffX = XL - XR;    //  >0ƫ��    <0ƫ��    
    diffY = YL - YR;
    
    //��Ⱥ�
    NormalizationX = ( (XL - XR) / (XL + XR) )*100;     //-100~100  >0ƫ��    <0ƫ��
    NormalizationY = ( (YL - YR) / (YL + YR) )*100;
}

//void Get_Basis_DG()
//{
//    Get_ADC();              //���û���ֵ���ж�ֱ���������
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
//    Save_Flash();           //���浽Flash
//}
