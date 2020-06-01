/*********************************************************************************************************************
 * @Project         Collection_Data_Car
 * @Version         ͨ����ͳ���Ʋɼ����ֵ����PWM
 * @Software        MDK 5.28
 * @Core            NXP RT1021DAG5A
 * @Date            2020-03-25
 * @Encoding        GB2312
 * @TabSize         4 Spaces
 * @GitHub          https://github.com/hao0527/Collection_Data_Car
 ********************************************************************************************************************/


#include "headfile.h"

uint8 send_buff[11];		        //����ת���ڷ�������

void main(void)
{
    DisableGlobalIRQ();
    board_init();                   //��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
    
    BEEP_Init();                    //��������ʼ��
    Key_allocation_init();          //������������ʼ��
//    mpu6050_self2_check();          //MPU6050�Լ캯��
//    mpu6050_init_hardware();        //MPU6050��ʼ��
    DG_ADC_Init();                  //���ADC��ʼ��
    PWM_allocation_init();          //����PWM����ܽ�
    BMQ_allocation_init();          //��������ʼ��
//    seekfree_wireless_init();       //��ʼ������ת����ģ��
    
    PIT_allocation_init();          //�����жϷ�����
    EnableGlobalIRQ(0);             //���ж������
    
    while(1)
    {
//        //���ݷ��ʹ��뽨�������ѭ����ʹ��if��ѯ��������ݲɼ��ɹ��ͷ�������
//		if(collection_succes)
//        {
//			collection_succes = 0;
//
//			//ǰ�����ֽ�Ϊʱ�䣬�������ṹ������ʱ��������Խ�ʱ�����������������ǽ��ܵ����ݺ�
//			//���Ը���ʱ�����жϰ��Ƿ��������ģ��Ƿ��ж���
//            send_buff[0] = 0;
//            send_buff[1] = 0;
//
//            send_buff[2] = X1;
//            send_buff[3] = X2;
//            send_buff[4] = X3;
//            send_buff[5] = X4;
//            send_buff[6] = X5;
//            send_buff[7] = X6;
//            send_buff[8] = X7;
//
//			//�������ֵת��Ϊ-128��+127  ��Ϊ���ת�Ǳ�������-400��+400֮�䣬
//			//��˶��ת�ǳ���420֮�����ֵ�ض���С��1�ģ�
//			//Ȼ���ڳ���128���ݷ�ΧҲ��һ������������-128��+127֮���ˡ�
//            send_buff[9] = (int32)(PWM_DuoJi-DuoJi_Mid)*128/420;
//
//			//�̶��ֽڣ���������У����߷������ۿɱ�ÿһ�����Ƿ���ȷ
//            send_buff[10] = 0x5a;
//
//            seekfree_wireless_send_buff(send_buff,11);      //��ʱ�������������Ի᲻�ᶪ��
//        }
    }
}
