/*
 * @Description  : NVIC封装实现
 * @Author       : FZU Liao
 * @Date         : 2021-12-29 16:55:44
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-03 12:33:01
 * @FilePath     : \BOARD\NVIC.c
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#include "NVIC.h"

void NVIC_SET_PRIORITY(NVIC_IRQn_enum INTtype_IRQn,uint8 Priority){
    if(INTtype_IRQn>>4==0){
        IP   &= ~(0x01<<INTtype_IRQn);
        IPH  &= ~(0x01<<INTtype_IRQn);
        IP   |= ((Priority%2)<<INTtype_IRQn);
        IPH  |= ((Priority/2)<<INTtype_IRQn);
    }else if(INTtype_IRQn>>4==1){
        IP2  &= ~(0x01<<(INTtype_IRQn-16));
        IP2H &= ~(0x01<<(INTtype_IRQn-16));
        IP2  |= ((Priority%2)<<(INTtype_IRQn-16));
        IP2H |= ((Priority/2)<<(INTtype_IRQn-16));
    }
}