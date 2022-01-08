/*
 * @Description  : 内嵌中断向量控制器封装
 * @Author       : FZU Liao
 * @Date         : 2021-12-29 16:55:37
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-03 12:32:56
 * @FilePath     : \BOARD\NVIC.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#ifndef __NVIC_H__
#define __NVIC_H__

#include "COMMON.h"

typedef enum{
    EXINT0_IRQn = 0x00,
    TIMER0_IRQn,
	INT1_IRQn,
	TIMER1_IRQn,
	UART1_IRQn,
	ADC_IRQn,
	LVD_IRQn,			
	UART2_IRQn = 0x10,
	SPI_IRQn,
	PWM1_IRQn,
	PWM2_IRQn,
	INT4_IRQn,
	CMP_IRQn,
	IIC_IRQn,
	USB_IRQn,
	UART3_IRQn = 0x20,
	UART4_IRQn,
}NVIC_IRQn_enum;

/**
 * @description: 设置中断优先级
 * @param INTtype_IRQn NVIC_IRQn_enum 中断号
 * @param Priority uint8 优先级,0~3,其中3为最高级
 * @return NULL
 * @example: NULL
 */
void NVIC_SET_PRIORITY(NVIC_IRQn_enum INTtype_IRQn,uint8 Priority);

#endif