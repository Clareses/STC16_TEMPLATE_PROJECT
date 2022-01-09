/*
 * @Description  : 步进电机控制实现
 * @Author       : FZU Liao
 * @Date         : 2022-01-03 15:48:25
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-09 22:25:11
 * @FilePath     : \TEMPLATE_PROJECT\CODES\DRIVER\STEP_MOTOR.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

//步进电机控制芯片HIP4082真值表
/*———————————————————————————————————————————————————————
 |  | ALI | BLI |   | ALO | AHO | BLO | BHO | |  STATE  |
 |  ————————————————————————————————————————— | ——————— |
 |  |  1  |  0  |   |  1  |  0  |  0  |  1  | | FORWARD |
 |  ————————————————————————————————————————— | ——————— |
 |  |  0  |  1  |   |  0  |  1  |  1  |  0  | |   BACK  |
 |  ————————————————————————————————————————— | ——————— |
 |  |  1  |  1  |   |  1  |  0  |  1  |  0  | |   STOP  | 
 |  ————————————————————————————————————————— | ——————— |
 |  |  0  |  0  |   |  0  |  1  |  0  |  1  | |   NULL  |
————————————————————————————————————————————————————————*/

#include "STEP_MOTOR.h"
#include "DELAY.h"

void STEP_MOTOR_INIT(STEP_MOTOR* MOTOR,PWM_CHANNEL_enum ALI,PWM_CHANNEL_enum BLI){
    MOTOR->MOTOR_PWM_Duty = 0;
    MOTOR->MOTOR_ALI = ALI;
    MOTOR->MOTOR_BLI = BLI;
    PWM_INIT_PWMCHANNEL(ALI,200,0);
    PWM_INIT_PWMCHANNEL(BLI,200,0);
}

void STEP_MOTOR_SET_DUTY(STEP_MOTOR* MOTOR,uint16 Duty){
    if(Duty > STEP_MOTOR_MAX_DUTY) Duty = STEP_MOTOR_MAX_DUTY;
    MOTOR->MOTOR_PWM_Duty = Duty;
    PWM_SET_DUTY(MOTOR->MOTOR_ALI,Duty);
    PWM_SET_DUTY(MOTOR->MOTOR_BLI,Duty);
}

void STEP_MOTOR_FORWARD(STEP_MOTOR* MOTOR){
    if(MOTOR->STATUS == STATUS_FORWARD) return;
    PWM_DISABLE(MOTOR->MOTOR_ALI);
    PWM_DISABLE(MOTOR->MOTOR_BLI);
    DELAY_us(500);
    MOTOR->STATUS = STATUS_FORWARD;
    PWM_ENABLE(MOTOR->MOTOR_ALI);
}

void STEP_MOTOR_STOP(STEP_MOTOR* MOTOR){
    if(MOTOR->STATUS == STATUS_STOP) return;
    PWM_DISABLE(MOTOR->MOTOR_ALI);
    PWM_DISABLE(MOTOR->MOTOR_BLI);
    DELAY_us(500);
    MOTOR->STATUS = STATUS_STOP;
    PWM_ENABLE(MOTOR->MOTOR_ALI);
    PWM_ENABLE(MOTOR->MOTOR_BLI);
}

void STEP_MOTOR_BACK(STEP_MOTOR* MOTOR){
    if(MOTOR->STATUS == STATUS_BACK) return;
    PWM_DISABLE(MOTOR->MOTOR_ALI);
    PWM_DISABLE(MOTOR->MOTOR_BLI);
    DELAY_us(500);
    MOTOR->STATUS = STATUS_BACK;
    PWM_ENABLE(MOTOR->MOTOR_BLI);
}

STEP_MOTOR_STATUS STEP_MOTOR_READ_STATUS(STEP_MOTOR* MOTOR){
    return MOTOR->STATUS;
}

uint32 STEP_MOTOR_GET_DUTY(STEP_MOTOR* MOTOR){
    return MOTOR->MOTOR_PWM_Duty;
}