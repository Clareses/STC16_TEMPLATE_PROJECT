/*
 * @Description  : 外部中断封装,包括中断初始化与参数设定等
 * @Author       : FZU Liao
 * @Date         : 2021-12-28 22:25:41
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-31 12:49:18
 * @FilePath     : \EXTINT\EXTINT.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#ifndef __EXTINT_H__
#define __EXTINT_H__
#include "COMMON.h"

//外部中断枚举
typedef enum{
    EXINT0 = 0, //支持下降沿/边沿模式
    EXINT1 = 1, //支持下降沿/边沿模式
    EXINT2 = 2, //仅支持下降沿模式
    EXINT3 = 3, //仅支持下降沿模式
    EXINT4 = 4  //仅支持下降沿模式
}EXINTn_enum;

//外部中断模式枚举
typedef enum{
    BOTH_MODE = 0,          //边沿模式
    FALLING_EDGE_MODE =1    //下降沿模式
}EXINT_MODE_enum;


//外部中断请求标志位清零宏定义
#define EXT0_CLEAR_FLAG (TCON &= (~(0x01 << 1)))		//外部中断 0 中断请求标志。中断服务程序中，硬件自动清零。
#define EXT1_CLEAR_FLAG (TCON &= (~(0x01 << 3)))		//外部中断 1 中断请求标志。中断服务程序中，硬件自动清零。
#define EXT2_CLEAR_FLAG (AUXINTIF &= (~(0x01 << 0)))	//外部中断 2 中断请求标志。需要软件清零。
#define EXT3_CLEAR_FLAG (AUXINTIF &= (~(0x01 << 1)))	//外部中断 3 中断请求标志。需要软件清零。
#define EXT4_CLEAR_FLAG (AUXINTIF &= (~(0x01 << 2)))	//外部中断 4 中断请求标志。需要软件清零。

/**
 * @description:    外部中断地址初始化函数,要使用外部中断必须先调用这个函数
 * @param           NULL
 * @return          NULL
 * @example:        NULL
 */
void EXINT_ADDRESS_INIT();

/**
 * @description:    外部中断初始化,设置中断外部函数,设置外部中断模式(仅支持外部中断0/1)
 * @param EXINTn    EXINTn_enum 外部中断号,为EXINT0~4,其中仅中断0/1支持模式设置
 * @param func      void无参函数指针,用于初始化中断函数
 * @param EXT_mode  EXINT_MODE_enum 外部中断模式设置,BOTH_MODE为边沿模式,FALLING_EDGE_MODE为下降沿模式,除中断0/1外固定填入1
 * @return          NULL
 * @example:        EXINT_INT(EXINT0,BOTH_MODE);
 */
void EXINT_INIT(EXINTn_enum EXINTn,void (*func)(),EXINT_MODE_enum EXT_mode);

/**
 * @description:    设置/修改外部中断函数
 * @param EXINTn    EXINTn_enum 外部中断号,为EXINT0~4
 * @param func      void无参函数指针
 * @return          NULL
 * @example:        EXINT_SET_FUNC();
 */
void EXINT_SET_FUNC(EXINTn_enum EXINTn,void (*func)());

/**
 * @description:    使能外部中断
 * @param EXINTn    EXINTn_enum 外部中断号,为EXINT0~4
 * @return          NULL
 * @example:        EXINT_ENABLE(EXINT0);
 */
void EXINT_ENABLE(EXINTn_enum EXINTn);

/**
 * @description:    终止使能外部中断
 * @param EXINTn    EXINTn_enum 外部中断号,为EXINT0~4
 * @return          NULL
 * @example:        EXINT_DISABLE(EXINT0);
 */
void EXINT_DISABLE(EXINTn_enum EXINTn);

#endif