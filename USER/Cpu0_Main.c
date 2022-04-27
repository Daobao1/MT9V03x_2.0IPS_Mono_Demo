/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file            main
 * @company         成都逐飞科技有限公司
 * @author          逐飞科技(QQ3184284598)
 * @version         查看doc内version文件 版本说明
 * @Software        tasking v6.3r1
 * @Target core     TC264D
 * @Taobao          https://seekfree.taobao.com/
 * @date            2020-3-23
 ********************************************************************************************************************/
 
#include "headfile.h"


int core0_main(void)
{
    get_clk();//获取时钟频率  务必保留

    //目前的库采集总钻风 图像最后一列为固定的黑色
    //这是由于单片机造成的，不是摄像头的问题

    ips200_init();  //初始化IPS屏幕
    ips200_showstr(0, 0, "SEEKFREE MT9V03x");
    ips200_showstr(0, 1, "Initializing...");
    //如果屏幕没有任何显示，请检查屏幕接线

    mt9v03x_init();
    //如果屏幕一直显示初始化信息，请检查摄像头接线
    //如果使用主板，一直卡在while(!uart_receive_flag)，请检查是否电池连接OK?或者摄像头的配置串口与单片机连接是否正确
    //如果图像只采集一次，请检查场信号(VSY)是否连接OK?
	IfxCpu_emitEvent(&g_cpuSyncEvent);
	IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
    enableInterrupts();

    while (TRUE)
    {
        if(mt9v03x_finish_flag)
        {
            ips200_displayimage032(mt9v03x_image[0], MT9V03X_W, MT9V03X_H);
            mt9v03x_finish_flag = 0;//在图像使用完毕后  务必清除标志位，否则不会开始采集下一幅图像
            //注意：一定要在图像使用完毕后在清除此标志位
        }
    }
}

