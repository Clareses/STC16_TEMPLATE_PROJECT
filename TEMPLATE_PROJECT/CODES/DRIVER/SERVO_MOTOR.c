/*
 * @Description  : 伺服电机控制实现
 * @Author       : FZU Liao
 * @Date         : 2022-01-03 14:35:08
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-06 00:13:35
 * @FilePath     : \TEMPLATE_PROJECT\CODES\DRIVER\SERVO_MOTOR.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#include "SERVO_MOTOR.h"
#include "..\BOARD\PWM.h"

#define SERVO_OUTPUT PWMB_CH1_P74

void SERVO_INIT_MOTOR(){
    PWM_INIT_PWMCHANNEL(SERVO_OUTPUT,200,3000);
    PWM_ENABLE(SERVO_OUTPUT);
}

void SERVO_SET_ANGLE(short Angle){
    uint16 DUTY;
    if(Angle>75) Angle = 75;
    if(Angle<-75) Angle = -75;
    DUTY = (Angle*2000/90);
    PWM_SET_DUTY(SERVO_OUTPUT,3000+DUTY);
}

void SERVO_DEINIT_MOTOR(){
    PWM_DISABLE(SERVO_OUTPUT);
}