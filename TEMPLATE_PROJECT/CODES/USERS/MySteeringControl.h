/*
 * @Description  : 舵机控制系统
 * @Author       : FZU Liao
 * @Date         : 2022-01-06 16:57:52
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-10 13:08:52
 * @FilePath     : \TEMPLATE_PROJECT\CODES\USERS\MySteeringControl.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __STREERING_CONTROL__
#define __STREERING_CONTROL__

#include "MySteeringPIDAdapter.h"
#include "EM_Calc.h"


void MyStreeringMotor_INIT(){
    SERVO_INIT_MOTOR();
}

float Streering_Control(int* EM_Data){
    float CURRENT_INPUT;
    float ANGLE;
    float temp;
    //接收传入的已经滤波过的电磁信号
    CURRENT_INPUT = EM_CACL_POS_RES(EM_Data);
    //利用电磁信号计算舵机大致摆角（调用PIDadapter算ERROR与目标值）
    ANGLE = Calc_SteeringMotor_ANGLE(CURRENT_INPUT);
    //输出到舵机
    SERVO_SET_ANGLE(ANGLE);
    //返回摆角
    return ANGLE;
}

#endif