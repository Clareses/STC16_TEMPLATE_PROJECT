/*
 * @Description  : 通用头文件，包含了1.引脚地址定义，2.数据类型定义
 * @Author       : FZU Liao
 * @Date         : 2021-12-28 22:01:20
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-01 21:24:03
 * @FilePath     : \COMMON.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */
#ifndef __COMMON_H__
#define __COMMON_H__
#include "STC16Fxx.h"

//数据声明
typedef unsigned char uint8;
typedef unsigned int  uint16;
typedef unsigned long uint32;

typedef signed char int8;
typedef signed int  int16;
typedef signed long int32;

//易变型变量的定义，防止编译器自动优化
typedef volatile uint8  vuint8;
typedef volatile uint16 vuint16;
typedef volatile uint32 vuint32;

#endif