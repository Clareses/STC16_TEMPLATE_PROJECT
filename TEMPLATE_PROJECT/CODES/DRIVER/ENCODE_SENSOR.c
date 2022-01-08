/*
 * @Description  : 编码器测速实现
 * @Author       : FZU Liao
 * @Date         : 2022-01-03 12:31:35
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-03 15:47:08
 * @FilePath     : \DRIVER\ENCODE_SENSOR.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#include "ENCODE_SENSOR.h"

void ENCODING_INIT(ENCODING_OUTPUT_enum TIMERx_Pxx){
    TIMER_INIT_TIMERx(TIMERx_Pxx,C,65535,0,0,0);
    TIMER_CLEAN_COUNTER(TIMERx_Pxx);
    TIMER_ENABLE(TIMERx_Pxx);
}

uint32 ENCODING_READ_RESULT(ENCODING_OUTPUT_enum TIMERx_Pxx){
    uint32 RESULT;
    RESULT = TIMER_READ_COUNTER(TIMERx_Pxx);
    TIMER_CLEAN_COUNTER(TIMERx_Pxx);
    return RESULT;
}

void ENCODING_DEINIT(ENCODING_OUTPUT_enum TIMERx_Pxx){
    TIMER_INIT_TIMERx(TIMERx_Pxx,T,0,0,0,0);
    TIMER_DISABLE(TIMERx_Pxx);
}