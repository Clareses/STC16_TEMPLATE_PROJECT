/*
 * @Description  : 模数转换封装
 * @Author       : FZU Liao
 * @Date         : 2022-01-01 18:18:40
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-01 19:49:35
 * @FilePath     : \ADC\ADC.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __ADC_H__
#define __ACD_H__

#include "COMMON.h"

typedef enum{
    ADC_CHANNEL_P10 , ADC_CHANNEL_P11 , ADC_CHANNEL_P54,
    ADC_CHANNEL_P13 , ADC_CHANNEL_P14 , ADC_CHANNEL_P15,
    ADC_CHANNEL_P16 , ADC_CHANNEL_P17 , ADC_CHANNEL_P00,
    ADC_CHANNEL_P01 , ADC_CHANNEL_P02 , ADC_CHANNEL_P03,
    ADC_CHANNEL_P04 , ADC_CHANNEL_P05 , ADC_CHANNEL_P06
}ADC_CHANNEL_PIN;

typedef enum{
    ADC_CLK_MODE1,
    ADC_CLK_MODE2,
    ADC_CLK_MODE3,
    ADC_CLK_MODE4,
    ADC_CLK_MODE5,
    ADC_CLK_MODE6,
    ADC_CLK_MODE7,
    ADC_CLK_MODE8,
    ADC_CLK_MODE9,
    ADC_CLK_MODE10,
    ADC_CLK_MODE11,
    ADC_CLK_MODE12,
    ADC_CLK_MODE13,
    ADC_CLK_MODE14,
}ADC_CLK_MODE;

/**
 * @description: ADC使能，开启模数转换模块
 * @param NULL
 * @return NULL
 * @example: NULL
 */
void ADC_ENABLE();

/**
 * @description: ADC取消使能，关闭数模转换
 * @param NULL
 * @return NULL
 * @example: NULL
 */
void ADC_DISABLE();

/**
 * @description: ADC模式初始化
 * @param ADC_CLK_MODEx ADC时钟设置，x可为1~15,ADCCLK=SYSCLK/2/x
 * @return NULL
 * @note MODE尽量不要小于3，若低于3会少于工作最短周期限制
 * @example: 
 */
void ADC_INIT(ADC_CLK_MODE ADC_CLK_MODEx);

/**
 * @description: 进行一次ADC取值
 * @param ADC_CHANNEL_Pxx ADC_CHANNEL_PIN
 * @return uint16 ADC_RES
 * @warning 在调用此函数前请确保对应GPIO通道处于高阻模式
 * @example: 
 */
uint16 ADC_READ(ADC_CHANNEL_PIN ADC_CHANNEL_Pxx);

#endif