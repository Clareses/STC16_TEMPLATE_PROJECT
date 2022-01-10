/*
 * @Description  : 舵机控制系统
 * @Author       : FZU Liao
 * @Date         : 2022-01-06 16:57:52
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-10 09:35:48
 * @FilePath     : \TEMPLATE_PROJECT\CODES\USERS\MySteeringControl.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __STREERING_CONTROL__
#define __STREERING_CONTROL__

#include "MySteeringPIDAdapter.h"

void MyStreeringMotor_INIT();

int Streering_Control(int* EM_Data){
    //接收传入的已经滤波过的电磁信号
    //利用电磁信号计算舵机大致摆角（调用PIDadapter算ERROR与目标值）
    //调用舵机控制系统输出摆角
    //返回摆角
}

#endif