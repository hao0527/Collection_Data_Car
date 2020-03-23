/*********************************************************************************************************************
 * @Project         Collection_Data_Car
 * @Version         ͨ����ͳ���Ʋɼ����ֵ����PWM
 * @Software        MDK 5.28
 * @Core            NXP RT1021DAG5A
 * @Date            2020-03-23
 * @Encoding        GB2312
 * @TabSize         4 Spaces
 * @GitHub          https://github.com/hao0527/Collection_Data_Car
 ********************************************************************************************************************/


#include "headfile.h"


uint16 adc_value;
void main(void)
{
    DisableGlobalIRQ();
    board_init();                   //��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
    BEEP_Init();
    Key_allocation_init();
    DG_ADC_Init();                  //���ADC��ʼ��
    PWM_allocation_init();          //����PWM����ܽ�
    BMQ_allocation_init();

    //�˴���д�û�����(���磺�����ʼ�������)
    PIT_allocation_init();          //�����жϷ�����
    EnableGlobalIRQ(0);             //���ж������
    while(1)
    {
        //�˴���д��Ҫѭ��ִ�еĴ���
    }
}
