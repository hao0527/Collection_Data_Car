#include "headfile.h"
//�ռ��ĳ���������ɸ���collection data����

int collection_succes;                               //ȫ�ֱ���  1��ad���ݲɼ����   0��ad����δ�ɼ����

void ad_collection(void)
{
    X1 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
    X2 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
    X3 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
    X4 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
    X5 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
    X6 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);
    X7 = adc_mean_filter(ADC_1,ADC1_CH0_B12,12);

    collection_succes = 1;
}

//��Ҳ��ֻ��һ�������� �����˺��ڰ����ϲ���