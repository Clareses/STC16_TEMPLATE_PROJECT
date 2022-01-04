/*
 * @Description  : 步进电机控制封装
 * @Author       : FZU Liao
 * @Date         : 2022-01-03 15:48:15
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-04 23:04:24
 * @FilePath     : \TEMPLATE_PROJECT\CODES\DRIVER\STEP_MOTOR.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __STEP_MOTOR_H__
#define __STEP_MOTOR_H__

#include "..\BOARD\PWM.h"

struct STEP_MOTOR_STRUCT{
    PWM_CHANNEL_enum MOTOR_ALI;
    PWM_CHANNEL_enum MOTOR_BLI;
    uint16 MOTOR_PWM_Duty;
};

typedef struct STEP_MOTOR_STRUCT STEP_MOTOR;

/**
 * @description: 初始化步进电机
 * @param MOTOR STEP_MOTOR 步进电机指针
 * @param ALI PWM_CHANNEL_enum PWM通道引脚
 * @param BLI PWM_CHANNEL_enum PWM通道引脚
 * @return NULL
 * @example:
 */
void STEP_MOTOR_INIT(STEP_MOTOR* MOTOR,PWM_CHANNEL_enum ALI,PWM_CHANNEL_enum BLI);

/**
 * @description: 步进电机动力设置
 * @param MOTOR STEP_MOTOR 电机指针
 * @param Duty  动力系数,为0~10000
 * @return NULL
 * @example: 
 */
void STEP_MOTOR_SET_DUTY(STEP_MOTOR* MOTOR,uint16 Duty);

/**
 * @description: 控制前进供电
 * @param MOTOR STEP_MOTOR 电机指针
 * @return NULL
 * @example: 
 */
void STEP_MOTOR_FORWARD(STEP_MOTOR* MOTOR);

/**
 * @description: 控制刹车
 * @param MOTOR STEP_MOTOR 电机指针
 * @return NULL
 * @example: 
 */
void STEP_MOTOR_STOP(STEP_MOTOR* MOTOR);

/**
 * @description: 控制后退供电
 * @param MOTOR STEP_MOTOR 电机指针
 * @return NULL
 * @example: 
 */
void STEP_MOTOR_BACK(STEP_MOTOR* MOTOR);

#endif