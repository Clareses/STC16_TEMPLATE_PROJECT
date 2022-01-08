/*
 * @Description  : 定时器相关封装
 * @Author       : FZU Liao
 * @Date         : 2021-12-29 17:37:20
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-03 14:07:03
 * @FilePath     : \BOARD\TIMER.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#ifndef __TIMER_H__
#define __TIMER_H__

#include "COMMON.h"

typedef enum{
    Timer0 = 0,
    Timer1,
    Timer2,
    Timer3,
    Timer4
}TIMER_enum;

struct TIMER_NORMAL_TYPE{
    uint8 TIMER_ID;
    uint32 time_ms;
    void (*TIMER_INT_FUNC)();
    uint8 ENABLE_bit;
    uint8 TorC_bit;
    uint8 TnCLKO_bit;
    uint8 F_Divider_bit;
};

struct TIMER_T01_TYPE{
    struct TIMER_NORMAL_TYPE *TIMER_NORMAL;
    uint8 M0_bit;
    uint8 M1_bit;
};

struct TIMER_T2_TYPE{
    struct TIMER_NORMAL_TYPE TIMER_NORMAL;
};

struct TIMER_T34_TYPE{
    struct TIMER_NORMAL_TYPE *TIMER_NORMAL;
    uint8 Pin_choose_bit;
};

typedef enum{
    T = 0,
    C = 1
}TIMER_COUNTER_enum;

typedef enum{
    MODE0,
    MODE1,
    MODE2,
    MODE3
}T01_MODE_enum;

typedef enum{
    T3P04_T4P06_T3CLKOP05_T4CLKOP07 = 0,
    T3P00_T4P02_T3CLKOP01_T4CLKOP03 = 1
}T34_PIN_enum;

/**
 * @description: TIMER总体初始化，要使用TIMER必须先调用该函数
 * @param *
 * @return *
 * @example: 
 */
void TIMER_ADDRESS_INIT();

/**
 * @description: Timer周期设置
 * @param Timerx TIMER_enum Timer0~4
 * @param TorC TIMER_COUNTER_enum 模式选择位，可选值为T(Timer)和C(Counter)
 * @param times uint32  如果是T模式，则单位为ms，如过是C模式，单位为次;每xms/x次后触发中断
 * @return *
 * @example: 
 */
void TIMER_SET_TIMES(TIMER_enum Timerx,TIMER_COUNTER_enum TorC,uint32 times);

/**
 * @description: 初始化TIMER,包括中断函数、计数/计时模式设置、分频设置、输出/输入设置
 * @param Timerx TIMER Timer0~4
 * @param TorC TIMER_COUNTER_enum 模式选择位，可选值为T(Timer)和C(Counter)
 * @param times uint32 如果是T模式，则单位为ms，如过是C模式，单位为次;每xms/x次后触发中断
 * @param F_Div uint8 是否分频，0/1为不分和分，若分频，则周期T=SysCLK/12
 * @param is_CLKOUT uint8 是否作为时钟输出，若为1，则会周期取反对应输出引脚的电平
 * @param func void无参函数指针，中断函数设置
 * @return NULL
 * @example: 
 */
void TIMER_INIT_TIMERx(TIMER_enum Timerx,TIMER_COUNTER_enum TorC,uint32 times,uint8 F_Div,uint8 is_CLKOUT,void (*func)());

/**
 * @description: Timer0和Timer1的模式设置
 * @param Timerx TIMER Timer0~1
 * @param Mode T01_MODE_enum
 *  可选值为:
 *      MODE0   16位自动重载
 *      MODE1   16位非自动重载 
 *      MODE2   8位自动重载
 *      MODE3   16位自动重载(中断优先级MAX,仅T0支持)
 * @return NULL
 * @example: 
 */
void TIMER_T01_SETMODE(TIMER_enum Timerx,T01_MODE_enum Mode);

/**
 * @description: Timer3和Timer4的引脚选择
 * @param Timerx TIMER Timer3~4
 * @param Pin_Mode T34_PIN_enum
 *      T3P04_T4P06_T3CLKOP05_T4CLKOP07 = 0
 *      T3P00_T4P02_T3CLKOP01_T4CLKOP03 = 1 
 * @return NULL
 * @example: 
 */
void TIMER_T34_SETPIN(TIMER_enum Timerx,T34_PIN_enum Pin_Mode);

/**
 * @description: Timer使能
 * @param Timerx TIMER Timer0~4
 * @return NULL
 * @example: 
 */
void TIMER_ENABLE(TIMER_enum Timerx);

/**
 * @description: Timer取消使能
 * @param Timerx TIEMR Timer0~4
 * @return NULL
 * @example: 
 */
void TIMER_DISABLE(TIMER_enum Timerx);

/**
 * @description: 设置Timer中断函数
 * @param Timerx TIMER_enum
 * @return NULL
 * @example: 
 */
void TIMER_SET_TIMERFUNC(TIMER_enum Timerx,void (*func)());

/**
 * @description: 读取TIMER寄存器TH中的值(计数值)
 * @param Timerx TIMER_enum Timer0~4
 * @return RESULT uint32 读数结果
 * @example: 
 */
uint32 TIMER_READ_COUNTER(TIMER_enum Timerx);

/**
 * @description: 清空TIMER寄存器TH中的值(计数值)
 * @param Timerx TIMER_enum Timer0~4
 * @return *
 * @example: 
 */
void TIMER_CLEAN_COUNTER(TIMER_enum Timerx);

#endif