/*
 * @Description  : 延时封装
 * @Author       : FZU Liao
 * @Date         : 2021-12-31 13:27:45
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-07 22:50:09
 * @FilePath     : \TEMPLATE_PROJECT\CODES\BOARD\DELAY.c
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#include "DELAY.h"

uint16 nCLK_ms = 0;
uint16 nCLK_us = 0;

void DELAY_INIT(){
    nCLK_ms = SYS_CLK/9000;
    nCLK_us = SYS_CLK/7000000;
}

void DELAY_ms(uint16 ms){
    uint16 i;
    while(ms--){
        i = nCLK_ms;
        while(i--);
    }
}

void DELAY_us(uint32 us){
    uint16 i;
    while(us--){
        i=nCLK_us;
        while(i--);
    }
}