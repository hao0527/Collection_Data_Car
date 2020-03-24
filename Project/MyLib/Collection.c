#include "headfile.h"
//收集的程序嫖自逐飞给的collection data工程

int collection_succes;                               //全局变量  1：ad数据采集完成   0：ad数据未采集完成

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

//这也就只有一个函数？ 别忘了后期把它合并掉