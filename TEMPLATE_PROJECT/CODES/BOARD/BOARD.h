/*
 * @Description  : 对MCU的一些初始化，包括初始化时钟与初始化总中断
 * @Author       : FZU Liao
 * @Date         : 2021-12-28 21:57:49
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-29 21:13:12
 * @FilePath     : \Board\Board.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include "COMMON.h"

//MCU频率设定(可选值: 30000000, 27000000. 24000000, 22118400, 20000000, 18432000,0)
#define FOSC					30000000
#define EXTERNAL_CRYSTA_ENABLE 	0           //使用外部晶振
#define ENABLE_IAP 				1	        //开启一键下载功能

//MCU频率
// extern uint32 SYS_CLK;

/**
 * @description: MCU初始化
 * @param *
 * @return *
 */
void BOARD_INIT();

/**
 * @description: 总中断取消使能
 * @param *
 * @return *
 */
void IQR_Disable_ALL();

/**
 * @description: 总中断使能
 * @param *
 * @return *
 */
void IQR_Enable_ALL();

#endif