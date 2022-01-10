/*
 * @Description  : Board.h的实现文件
 * @Author       : FZU Liao
 * @Date         : 2021-12-28 21:57:55
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-10 21:36:03
 * @FilePath     : \TEMPLATE_PROJECT\CODES\BOARD\BOARD.c
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#include "BOARD.h"

void BOARD_INIT(){
    P0M0 = 0x00;
	P0M1 = 0x00;
	P1M0 = 0x00;
	P1M1 = 0x00;
	P2M0 = 0x00;
	P2M1 = 0x00;
	P3M0 = 0x00;
	P3M1 = 0x00;
	P4M0 = 0x00;
	P4M1 = 0x00;
	P5M0 = 0x00;
	P5M1 = 0x00;
	P6M0 = 0x00;
	P6M1 = 0x00;
	P7M0 = 0x00;
	P7M1 = 0x00;
}

void IQR_Disable_ALL(){
    EA=0;
}

void IQR_Enable_ALL(){
    EA=1;
}