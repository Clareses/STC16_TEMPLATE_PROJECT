/*
 * @Description  : 电磁传感器实现
 * @Author       : FZU Liao
 * @Date         : 2022-01-03 15:31:32
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-08 17:24:14
 * @FilePath     : \TEMPLATE_PROJECT\CODES\DRIVER\EM_SENSOR.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */
#include "EM_SENSOR.h"
#include "..\BOARD\ADC.h"

void EM_INIT_SENSOR(){
    ADC_INIT(ADC_CLK_MODE6);
    ADC_ENABLE();
}

void EM_READ_SENSOR(int* DATA_LIST){
    DATA_LIST[0] = ADC_READ(ADC_CHANNEL_P00);
    DATA_LIST[1] = ADC_READ(ADC_CHANNEL_P01);
    DATA_LIST[2] = ADC_READ(ADC_CHANNEL_P05);
    DATA_LIST[3] = ADC_READ(ADC_CHANNEL_P06);
}

void EM_DEINIT_SENSOR(){
    ADC_DISABLE();
}