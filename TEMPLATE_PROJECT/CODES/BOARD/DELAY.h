/*
 * @Description  : DELAY，软件延时
 * @Author       : FZU Liao
 * @Date         : 2021-12-31 13:24:16
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-31 13:27:20
 * @FilePath     : \DELAY\DELAY.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#ifndef __DELAY_H__
#define __DELAY_H__
#include "COMMON.h"

/**
 * @description: 软件延时初始化
 * @param *
 * @return *
 * @example: 
 */
void DELAY_INIT();

/**
 * @description: 延时ms
 * @param ms uint16 ms数
 * @return *
 * @example: 
 */
void DELAY_ms(uint16 ms);

/**
 * @description: 延时us
 * @param us uint32 us数
 * @return *
 * @example: 
 */
void DELAY_us(uint32 us);

#endif