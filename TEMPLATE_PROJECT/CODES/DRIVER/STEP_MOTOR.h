/*
 * @Description  : 步进电机模块
 * @Author       : FZU Liao
 * @Date         : 2022-01-07 23:02:40
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-07 23:13:16
 * @FilePath     : \TEMPLATE_PROJECT\CODES\DRIVER\STEP_MOTOR.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __STEP_MOTOR_H__

#include "COMMON.h"
#include "../BOARD/HEADFILE.h"

#define STEP_PWM_OUTPUT_PIN PWMA_CH1P_P60

typedef enum{
    FORWARD = 0,
    BACK = 1
}STEPMOTOR_MODE;

/**
 * @description: 电机模块初始化
 * @param *
 * @return *
 * @example: 
 */
void STEP_MOTOR_INIT();

/**
 * @description: 电机转速函数
 * @param duty PWM占空比，0~10000
 * @return *
 * @example: 
 */
void STEP_MOTOR_DUTY(int duty);

/**
 * @description: 
 * @param MODE STEPMOTOR_MODE
 *  可选值：
 *      FORWARD 为前进， BACK 为后退
 * @return *
 * @example: 
 */
void STEP_MOTOR_MODE(STEPMOTOR_MODE MODE);

#endif
