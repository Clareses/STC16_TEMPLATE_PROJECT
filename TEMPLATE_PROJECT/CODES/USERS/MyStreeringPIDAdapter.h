/*
 * @Description  : 舵机控制PID适配器
 * @Author       : FZU Liao
 * @Date         : 2022-01-06 16:58:50
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-06 21:53:05
 * @FilePath     : \TEMPLATE_PROJECT\CODES\USERS\MyStreeringAdapter.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */
#ifndef __STREERING_PID_ADAPTER__
#define __STREERING_PID_ADAPTER__

int Calc_StreeringMotor_Angle(int* data){
    /*暂时考虑是...输入8个电磁值，然后分别计算8个PID的值，去最大最小后取平均
    这有点麻烦...也可以考虑另外一些算法...比如先处理8个电磁值，然后再输入PID计算*/
}

#endif