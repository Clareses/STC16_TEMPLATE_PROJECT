/*
 * @Description  : 舵机控制PID适配器
 * @Author       : FZU Liao
 * @Date         : 2022-01-06 16:58:50
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-10 11:45:05
 * @FilePath     : \TEMPLATE_PROJECT\CODES\USERS\MySteeringPIDAdapter.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */
#ifndef __STREERING_PID_ADAPTER__
#define __STREERING_PID_ADAPTER__

#include "SERVO_MOTOR.h"
#include "PID.h"

#define STEERING_Kp 1
#define STEERING_Ki 1
#define STEERING_Kd 1

PID MySTEERING_PID;

void MySTEERING_PID_INIT(){
    PID_INIT_NEWPID(&MySTEERING_PID,STEERING_Kp,STEERING_Ki,STEERING_Kd,0,PID_REALIZE_MODE);
}

//输出值应为-10~+10
float Calc_SteeringMotor_ANGLE(int CURRENT_INPUT){
    return PID_CALC_RESULT(&MySTEERING_PID,CURRENT_INPUT);
}

#endif