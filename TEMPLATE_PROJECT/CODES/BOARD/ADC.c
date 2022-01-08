/*
 * @Description  : ADC封装实现
 * @Author       : FZU Liao
 * @Date         : 2022-01-01 18:18:45
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-05 21:57:53
 * @FilePath     : \TEMPLATE_PROJECT\CODES\BOARD\ADC.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */
#include "ADC.h"

void ADC_ENABLE(){
    ADC_CONTR |= 0x80;
}

void ADC_DISABLE(){
    ADC_CONTR &= 0x7F;
}

void ADC_INIT(ADC_CLK_MODE ADC_CLK_MODEx){
    ADCCFG |= ADC_CLK_MODEx & 0x0F;
    ADCCFG |= 1<<5;	
}

uint16 ADC_READ(ADC_CHANNEL_PIN ADC_CHANNEL_Pxx){
    uint16 ADC_RESULT;
	ADC_CONTR &= (0xF0);
	ADC_CONTR |= ADC_CHANNEL_Pxx;
	ADC_CONTR |= 0x40;
	while (!(ADC_CONTR & 0x20));
	ADC_CONTR &= ~0x20;
    ADC_RESULT = ADC_RES;	
    ADC_RESULT <<= 8;
    ADC_RESULT |= ADC_RESL;
	ADC_RES = 0;
	ADC_RESL = 0;
	ADC_RESULT >>= 12;
	return ADC_RESULT;
}