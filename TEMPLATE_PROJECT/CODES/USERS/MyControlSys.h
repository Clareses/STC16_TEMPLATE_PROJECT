/*
 * @Description  : 总控制系统，负责信号采集、电机输出等配置
 * @Author       : FZU Liao
 * @Date         : 2022-01-06 16:58:07
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-06 21:40:34
 * @FilePath     : \TEMPLATE_PROJECT\CODES\USERS\MyControlSys.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __CONTROL_SYS__
#define __CONTROL_SYS__

#include "HEADFILE.h"

void MySYS_INIT(){
    //初始化两个电机、信号采集系统等
}

void My_routineTask(){
    //调用电磁传感器，获取数据后滤波
    //滤波结束后的值，进行处理，数据传给舵机控制系统控制舵机，并接收一个返回值（舵机打角的角度）
    //读取计数器，处理
    //利用舵机打角角度，处理出速度目标值
    //传两个值给电机控制系统（一个当前值，一个目标值）
}

#endif