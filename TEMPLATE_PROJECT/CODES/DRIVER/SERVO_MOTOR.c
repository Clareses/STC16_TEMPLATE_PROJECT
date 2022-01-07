/*
 * @Description  : 伺服电机控制实现
 * @Author       : FZU Liao
 * @Date         : 2022-01-03 14:35:08
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-07 22:08:26
 * @FilePath     : \TEMPLATE_PROJECT\CODES\DRIVER\SERVO_MOTOR.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#include "SERVO_MOTOR.h"
#include "DELAY.h"
#include "..\BOARD\PWM.h"

#define SERVO_OUTPUT PWMB_CH1_P74

#define MAX_ANGLE 10

void SERVO_INIT_MOTOR(){
    PWM_INIT_PWMCHANNEL(SERVO_OUTPUT,50,760);
    PWM_ENABLE(SERVO_OUTPUT);
}

void SERVO_SET_ANGLE(int Angle){
    uint16 DUTY;
    if(Angle>MAX_ANGLE) Angle = MAX_ANGLE;
    if(Angle<-MAX_ANGLE) Angle = -MAX_ANGLE;
    DUTY = (Angle*30);
    PWM_SET_DUTY(SERVO_OUTPUT,760+DUTY);
    DELAY_ms(50);
}

void SERVO_DEINIT_MOTOR(){
    PWM_DISABLE(SERVO_OUTPUT);
}