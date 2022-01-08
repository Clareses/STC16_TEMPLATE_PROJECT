/*
 * @Description  : GPIO的模式配置与读写,主要通过宏函数实现
 * @Author       : FZU Liao
 * @Date         : 2021-12-29 13:07:09
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-05 22:12:22
 * @FilePath     : \TEMPLATE_PROJECT\CODES\BOARD\GPIO.h
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#ifndef __GPIO_H__
#define __GPIO_H__

#include "COMMON.h"

//GPIO_MODE_REGISTER
#define PxM0(x)  (P##x##M0)
#define PxM1(x)  (P##x##M1)

//GPIO上拉电阻使能寄存器配置
#define PxPU(x)  (P##x##PU)

//GPIO_REGISTER
#define GPIO_PX(x) (P##x)


//寄存器定义
#define GPIO_P0 0
#define GPIO_P1 1
#define GPIO_P2 2
#define GPIO_P3 3
#define GPIO_P4 4
#define GPIO_P5 5
#define GPIO_P6 6
#define GPIO_P7 7

//引脚定义
#define    Pin_0     0x00
#define    Pin_1     0x02
#define    Pin_2     0x04
#define    Pin_3     0x08
#define    Pin_4     0x10
#define    Pin_5     0x20
#define    Pin_6     0x40
#define    Pin_7     0x80
#define    Pin_LOW   0x0F
#define    Pin_HIGH  0xF0
#define    Pin_ALL   0xFF

//Mode定义

#define    GPIO_WEAK_PULL_MODE          0
#define    GPIO_OUT_PULL_PUSH_MODE      1
#define    GPIO_IN_HIGH_IMPEDANCE_MODE  2
#define    GPIO_OUT_OPEN_DRAIN_MODE     3


//电平定义
#define   LOW   0
#define   HIGH  1


/**
 * @description:    GPIO模式设置
 * @param GPIO_Px   为GPIO_P0~7
 * @param Pin_x     为Pin_0~7(注意GPIO5无Pin5~7)，可以用或运算传入多个Pin
 * @param Mode 
 * 可选值为:
 *  GPIO_WEAK_PULL_MODE          弱上拉(准双向口)
 *  GPIO_OUT_PULL_PUSH_MODE      推挽输出
 *  GPIO_IN_HIGH_IMPEDANCE_MODE  高阻输入
 *  GPIO_OUT_OPEN_DRAIN_MODE     开漏输出
 * @return NULL
 * @example: GPIO_SET_MODE(GPIO_P0,Pin_0|Pin_1,GPIO_WEAK_PULL_MODE);  将P0寄存器的0、1引脚设置为准双向输出模式
 */
#define GPIO_SET_MODE(GPIO_Px,Pin_x,GPIO_MODE) do{  \
    PxM0(GPIO_Px)&=~Pin_x;                          \
    PxM1(GPIO_Px)&=~Pin_x;                          \
    PxM0(GPIO_Px)|=(GPIO_MODE%2)*(Pin_x);           \
    PxM1(GPIO_Px)|=(GPIO_MODE/2)*(Pin_x);           \
}while(0)                                           \

/**
 * @description: GPIO引脚输出
 * @param gpio_px PIO_Px GPIO_Px 为GPIO_P0~7
 * @param pin_x Pin_x 为Pin_0~7与Pin_ALL/HIGH/LOW(注意GPIO5无Pin5~7),可以用或运算传入多个Pin
 * @param El GPIO_EL GPIO电平,可选值为HIGH与LOW
 * @return NULL
 * @example: GPIO_WRITE(GPIO_P0,Pin_0|Pin_1,HIGH);  将P0寄存器的0、1引脚输出为高电平
 */
#define GPIO_WRITE(GPIO_Px,Pin_x,GPIO_EL) do{                   \
    if(GPIO_EL==LOW) GPIO_PX(GPIO_Px)&= ~(Pin_x);               \
    else GPIO_PX(GPIO_Px) |= (Pin_x);                           \
}while(0)                                                       \


/**
 * @description: GPIO引脚读取
 * @param gpio_px PIO_Px GPIO_Px 为GPIO_P0~7
 * @param pin_x Pin_x 为Pin_0~7(注意GPIO5无Pin5~7),不可同时读入多个引脚
 * @return GPIO_EL,HIGH为高电平,LOW为低电平
 * @example: NULL
 */
#define GPIO_READ_PIN(GPIO_Px,Pin_x) (GPIO_PX(GPIO_Px)&(Pin_x))!=0? HIGH : LOW

/**
 * @description: GPIO寄存器读取 
 * @param gpio_px GPIO_Px 为GPIO_P0~7
 * @return uint8 八位int
 * @example: NULL
 */
#define GPIO_READ_REGISTER(GPIO_Px) GPIO_PX(GPIO_Px)

/**
 * @description: GPIO引脚上拉电阻使能
 * @param gpio_px GPIO_Px 为GPIO_P0~7
 * @param pin_x Pin_x 为Pin_0~7(注意GPIO5无Pin5~7),可同时读入多个引脚
 * @return NULL
 * @example: NULL
 */
#define GPIO_PULLUP_ENABLE(GPIO_Px,Pin_x) PxPU(GPIO_Px)|=(Pin_x)

/**
 * @description: GPIO引脚上拉电阻取消使能
 * @param gpio_px GPIO_Px 为GPIO_P0~7
 * @param pin_x Pin_x 为Pin_0~7(注意GPIO5无Pin5~7),可同时读入多个引脚
 * @return NULL
 * @example: NULL
 */
#define GPIO_PULLUP_DISABLE(GPIO_Px,Pin_x) PxPU(GPIO_Px)&=~(Pin_x)

/**
 * @description: 翻转GPIO引脚输出
 * @param GPIO_Px IO组号
 * @param Pin_x   引脚号，可用|同时读入多个引脚
 * @return NULL
 * @example: NULL
 */
#define GPIO_REVERSE_PIN(GPIO_Px,Pin_x) do{     \
    uint8 temp = GPIO_PX(GPIO_Px)&Pin_x;        \
    GPIO_PX(GPIO_Px) &= ~Pin_x;                 \
    temp = ~temp;                               \
    temp &= Pin_x;                              \
    GPIO_PX(GPIO_Px) |= temp;                   \
}while(0)                                       \

#endif