/*********************************************************************************************************************
 * @Project         Collection_Data_Car
 * @Version         ͨ����ͳ���Ʋɼ����ֵ����PWM
 * @Software        MDK 5.28
 * @Core            NXP RT1021DAG5A
 * @Date            2020-06-02
 * @Encoding        GB2312
 * @TabSize         4 Spaces
 * @GitHub          https://github.com/hao0527/Collection_Data_Car
 ********************************************************************************************************************/


#include "headfile.h"

uint8 uart_data;
int i;
uint8 buff[10];

uint8 example_rx_buffer;
lpuart_transfer_t   example_receivexfer;
lpuart_handle_t     example_g_lpuartHandle;

void example_uart_callback(LPUART_Type *base, lpuart_handle_t *handle, status_t status, void *userData)
{
    if(kStatus_LPUART_RxIdle == status)
    {
        //�����Ѿ���д�뵽��֮ǰ���õ�BUFF��
        //������ʹ�õ�BUFFΪ example_rx_buffer
        uart_data = example_rx_buffer;//������ȡ��
        if(uart_data==0xA5) {i=0;}
        else if(uart_data==0x5A)
        {
//            uart_putbuff(USART_1,&buff[0],4);
            //У���Ƿ���մ���
            if((0xff&(buff[0]+buff[1]+buff[2]))==buff[3])
            {
                car_mode = buff[0];
                vx = uint8toint8(buff[1]);
                vy = uint8toint8(buff[2]);
            }
        }
        else
        {
            buff[i]=uart_data;
            i++;
        }
    }
    
    handle->rxDataSize = example_receivexfer.dataSize;  //��ԭ����������
    handle->rxData = example_receivexfer.data;          //��ԭ��������ַ
}

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
    
    uart_init(USART_1,115200,UART1_TX_B6,UART1_RX_B7);//����ͨ�ų�ʼ��
    uart_rx_irq(USART_1,1);         //�������ڽ����ж�
    
    //���ô��ڽ��յĻ�����������������
    example_receivexfer.dataSize = 1;
    example_receivexfer.data = &example_rx_buffer;
    
    //�����жϺ����������
    uart_set_handle(USART_1, &example_g_lpuartHandle, example_uart_callback, NULL, 0, example_receivexfer.data, 1);
    
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
