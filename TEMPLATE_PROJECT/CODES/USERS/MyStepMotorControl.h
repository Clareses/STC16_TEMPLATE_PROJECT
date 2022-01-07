/*
 * @Description  : 步进电机控制
 * @Author       : FZU Liao
 * @Date         : 2022-01-06 16:57:24
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-06 22:01:50
 * @FilePath     : \TEMPLATE_PROJECT\CODES\USERS\MyStepMotorControl.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __MyStepMotorControl__
#define __MyStepMotorControl__

#include "HEADFILE.h"
#include "STEP_MOTOR.h"

#define ERROR_RANGE 1

STEP_MOTOR MyStepMotor;

void MyStepMotor_INIT(){

}

void StepMotor_Control(uint16 CURRENT_SPEED,uint16 TARGET_SPEED){
    //加上特判，如果目标值为0，直接停止所有输出
    //加上特判，如果当前值不止第一次为0（曾经有过速度，而又降为0），则停止所有输出（断电保护，怕烧电机）
    //取得两个值后，进行判断，差值是否处于预定范围内，如果超出太多，直接调用刹车函数
    //如果进入可PWM调控的范围，则调用PID适配器中的计算函数，得到输出的PWM值
    //调用步进电机，输出PWM
}

#endif