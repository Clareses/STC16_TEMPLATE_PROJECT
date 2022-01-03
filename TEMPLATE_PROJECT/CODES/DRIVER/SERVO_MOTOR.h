/*
 * @Description  : 伺服电机控制封装
 * @Author       : FZU Liao
 * @Date         : 2022-01-03 14:34:30
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-03 15:33:19
 * @FilePath     : \DRIVER\SERVO_MOTOR.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __SERVO_MOTOR_H__
#define __SERVO_MOTOR_H__

/**
 * @description: 初始化伺服电机,使其角度保持在中央(0°)
 * @param NULL
 * @return NULL
 * @example: 
 */
void SERVO_INIT_MOTOR();

/**
 * @description: 设置伺服电机工作角度
 * @param Angle uint8 |Angle|<=150
 * @return *
 * @example: 
 */
void SERVO_SET_ANGLE(short Angle);

/**
 * @description: 逆初始化伺服电机
 * @param *
 * @return *
 * @example: 
 */
void SERVO_DEINIT_MOTOR();

#endif