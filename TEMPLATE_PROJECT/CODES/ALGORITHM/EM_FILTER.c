/*
 * @Description  : 电磁滤波器实现
 * @Author       : FZU Liao
 * @Date         : 2022-01-08 18:23:10
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-09 22:24:26
 * @FilePath     : \TEMPLATE_PROJECT\CODES\ALGORITHM\EM_FILTER.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#include "EM_FILTER.h"
#include "COMMON.h"

#define EM_MAX -100000
#define EM_MIN  100000

void EM_FILTER_INIT(EM_FILTER* FILTER,int max,int min){
    int index;
    FILTER->times = 0;
    for(index = 0 ; index<LIST_LENGTH ; index++){
        FILTER->FILTER_LIST[index] = 0;
        FILTER->MAX_LIST[index] = EM_MAX;
        FILTER->MIN_LIST[index] = EM_MIN;
    }
}

void EM_FILTER_ADD_SAMPLE(EM_FILTER* FILTER,int* DATA_SAMPLE_LIST){
    int index,temp;
    for(index=0;index<LIST_LENGTH;index++){
        temp = DATA_SAMPLE_LIST[index];
        if(temp>FILTER->MAX_RANGE) temp = FILTER->MAX_RANGE;
        if(temp<FILTER->MIN_RANGE) temp = FILTER->MIN_RANGE;
        FILTER->MAX_LIST[index] = FILTER->MAX_LIST[index]<temp ? temp : FILTER->MAX_LIST[index];
        FILTER->MIN_LIST[index] = FILTER->MIN_LIST[index]>temp ? temp : FILTER->MIN_LIST[index];
        FILTER->FILTER_LIST[index] += temp;
    }
    FILTER->times++;
}

void EM_FILTER_READ_RESULT(EM_FILTER* FILTER,int* RES_SET){
    int index;
    for(index=0;index<LIST_LENGTH;index++){
        if(FILTER->times>=3)
            RES_SET[index] = (FILTER->FILTER_LIST[index]-FILTER->MAX_LIST[index]-FILTER->MIN_LIST[index])/(FILTER->times-2);
        else
            RES_SET[index] = FILTER->FILTER_LIST[index];
    }
    EM_FILTER_INIT(FILTER,FILTER->MAX_RANGE,FILTER->MIN_RANGE);
}