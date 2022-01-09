/*
 * @Description  : 步进电机PID adapter，用于将PID输出转为步进电机的输出
 * @Author       : FZU Liao
 * @Date         : 2022-01-06 16:58:29
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-09 23:38:41
 * @FilePath     : \TEMPLATE_PROJECT\CODES\USERS\MyStepMotorPIDAdapter.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __STEPMOTOR_ADAPTER__
#define __STEPMOTOR_ADAPTER__

#include "PID.h"
#include "COMMON.h"
#include "TIMER.h"

#define STEPMOTOR_Kp 1
#define STEPMOTOR_Ki 1
#define STEPMOTOR_Kd 1

PID MySTEPMOTOR_PID;

void MySTEPMOTOR_PID_INIT(){
    PID_INIT_NEWPID(&MySTEPMOTOR_PID,STEPMOTOR_Kp,STEPMOTOR_Ki,STEPMOTOR_Kd,0,PID_INCREASE_MODE);
}

int Calc_StepMotor_PWM(uint16 CURRENT_SPEED,uint16 TARGET_SPEED){
    //设置目标参数
    PID_SET_TARGET(&MySTEPMOTOR_PID,TARGET_SPEED);
    //接收参数后调用PID，传入参数后得到PID计算出的结果，转为PWM值，并返回
    return PID_CALC_RESULT(&MySTEPMOTOR_PID,CURRENT_SPEED);
}


#endif