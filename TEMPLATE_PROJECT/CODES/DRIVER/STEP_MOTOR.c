/*
 * @Description  : 步进电机模块
 * @Author       : FZU Liao
 * @Date         : 2022-01-07 23:02:40
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-08 11:00:43
 * @FilePath     : \TEMPLATE_PROJECT\CODES\DRIVER\STEP_MOTOR.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#include "STEP_MOTOR.h"

void STEP_MOTOR_INIT(){
    PWM_INIT_PWMCHANNEL(STEP_PWM_OUTPUT_PIN,12500,0);
    GPIO_SET_MODE(GPIO_P6,Pin_0|Pin_4,GPIO_OUT_PULL_PUSH_MODE);
    STEP_MOTOR_MODE(FORWARD);
    PWM_ENABLE(STEP_PWM_OUTPUT_PIN);
}

void STEP_MOTOR_DUTY(int duty){
    PWM_SET_DUTY(STEP_PWM_OUTPUT_PIN,duty);
}

void STEP_MOTOR_MODE(STEPMOTOR_MODE MODE){
    GPIO_WRITE(GPIO_P6,Pin_4,MODE);
}