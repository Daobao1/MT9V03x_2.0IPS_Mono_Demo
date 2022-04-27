/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file            main
 * @company         �ɶ���ɿƼ����޹�˾
 * @author          ��ɿƼ�(QQ3184284598)
 * @version         �鿴doc��version�ļ� �汾˵��
 * @Software        tasking v6.3r1
 * @Target core     TC264D
 * @Taobao          https://seekfree.taobao.com/
 * @date            2020-3-23
 ********************************************************************************************************************/
 
#include "headfile.h"


int core0_main(void)
{
    get_clk();//��ȡʱ��Ƶ��  ��ر���

    //Ŀǰ�Ŀ�ɼ������ ͼ�����һ��Ϊ�̶��ĺ�ɫ
    //�������ڵ�Ƭ����ɵģ���������ͷ������

    ips200_init();  //��ʼ��IPS��Ļ
    ips200_showstr(0, 0, "SEEKFREE MT9V03x");
    ips200_showstr(0, 1, "Initializing...");
    //�����Ļû���κ���ʾ��������Ļ����

    mt9v03x_init();
    //�����Ļһֱ��ʾ��ʼ����Ϣ����������ͷ����
    //���ʹ�����壬һֱ����while(!uart_receive_flag)�������Ƿ�������OK?��������ͷ�����ô����뵥Ƭ�������Ƿ���ȷ
    //���ͼ��ֻ�ɼ�һ�Σ����鳡�ź�(VSY)�Ƿ�����OK?
	IfxCpu_emitEvent(&g_cpuSyncEvent);
	IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
    enableInterrupts();

    while (TRUE)
    {
        if(mt9v03x_finish_flag)
        {
            ips200_displayimage032(mt9v03x_image[0], MT9V03X_W, MT9V03X_H);
            mt9v03x_finish_flag = 0;//��ͼ��ʹ����Ϻ�  ��������־λ�����򲻻Ὺʼ�ɼ���һ��ͼ��
            //ע�⣺һ��Ҫ��ͼ��ʹ����Ϻ�������˱�־λ
        }
    }
}

