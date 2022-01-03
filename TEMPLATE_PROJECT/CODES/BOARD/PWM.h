/*
 * @Description  : PWM输出设置(比较简单...复杂的TIMER以后再封装，目前只能单方向输出PWM...)
 * @Author       : FZU Liao
 * @Date         : 2021-12-31 19:34:07
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-31 20:42:18
 * @FilePath     : \PWM\PWM.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 * note          : 在逐飞的板子上，有几个引脚已经被使用了:
 *                 P54被用作复位，P12被用作USB，应避免使用。
 */

#ifndef __PWM_H__
#define __PWM_H__

#include "COMMON.h"

#define PWM_MAX_DUTY 10000

typedef enum
{
    
	PWMA_CH1P_P10 = 0x00,
    PWMA_CH1N_P11,
	PWMA_CH1P_P20,		 
    PWMA_CH1N_P21,
	PWMA_CH1P_P60,		 
    PWMA_CH1N_P61,

	PWMA_CH2P_P12 = 0x10,
	PWMA_CH2N_P13,          
	PWMA_CH2P_P22,		 
    PWMA_CH2N_P23,
	PWMA_CH2P_P62,		 
    PWMA_CH2N_P63,

	PWMA_CH3P_P14 = 0x20,
    PWMA_CH3N_P15,
	PWMA_CH3P_P24,		 
    PWMA_CH3N_P25,
	PWMA_CH3P_P64,		 
    PWMA_CH3N_P65,

	PWMA_CH4P_P16 = 0x30,
    PWMA_CH4N_P17,
	PWMA_CH4P_P26,		 
    PWMA_CH4N_P27,
	PWMA_CH4P_P66,		 
    PWMA_CH4N_P67,
	PWMA_CH4P_P34,		 
    PWMA_CH4N_P33,
	
	PWMB_CH1_P20 = 0x40,
	PWMB_CH1_P17,
	PWMB_CH1_P00,
	PWMB_CH1_P74,

	PWMB_CH2_P21 = 0x50,
	PWMB_CH2_P54,
	PWMB_CH2_P01,
	PWMB_CH2_P75,

	PWMB_CH3_P22 = 0x60,
	PWMB_CH3_P33,
	PWMB_CH3_P02,
	PWMB_CH3_P76,

	PWMB_CH4_P23 = 0x70,
	PWMB_CH4_P34,
	PWMB_CH4_P03,
	PWMB_CH4_P77,

}PWM_CHANNEL_enum;

/**
 * @description: 对PWM初始化，包括通道、频率、占空比等
 * @param PWMn_CHx_Pin PWM_CHANNEL_enum
 * @param Frequecy uint32
 * @param Duty uint16 Duty/10000即为占空比
 * @return NULL
 * @example: 
 */
void PWM_INIT_PWMCHANNEL(PWM_CHANNEL_enum PWMn_CHx_Pin,uint32 Frequecy, uint16 Duty);

/**
 * @description: 设置PWM占空比
 * @param PWMn_CHx_Pin PWM_CHANNEL_enum
 * @param Duty uint16 Duty/10000即为占空比
 * @return *
 * @example: 
 */
void PWM_SET_DUTY(PWM_CHANNEL_enum PWMn_CHx_Pin,uint16 Duty);

/**
 * @description: 使能PWM定时器
 * @param PWMn_CHx_Pin PWMA/B_Pxx
 * @return *
 * @example: 
 */
void PWM_ENABLE(PWM_CHANNEL_enum PWMn_CHx_Pin);

/**
 * @description: 取消PWM定时器使能
 * @param PWMn_CHx_Pin PWMA/B_Pxx
 * @return *
 * @example: 
 */
void PWM_DISABLE(PWM_CHANNEL_enum PWMn_CHx_Pin);

#endif