/*
 * @Description  : Board.h的实现文件
 * @Author       : FZU Liao
 * @Date         : 2021-12-28 21:57:55
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-28 22:24:30
 * @FilePath     : \Board\board.c
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#include "BOARD.h"

void BOARD_INIT(){

}

void IQR_Disable_ALL(){
    EA=0;
}

void IQR_Enable_ALL(){
    EA=1;
}