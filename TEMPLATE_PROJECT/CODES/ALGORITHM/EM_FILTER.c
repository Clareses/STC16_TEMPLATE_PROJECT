/*
 * @Description  : 电磁滤波器实现
 * @Author       : FZU Liao
 * @Date         : 2022-01-08 18:23:10
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-08 23:21:21
 * @FilePath     : \TEMPLATE_PROJECT\CODES\ALGORITHM\EM_FILTER.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#include "EM_FILTER.h"
#include "COMMON.h"

#define EM_MAX -100000
#define EM_MIN  100000
#define LIST_LENGTH 4

int times;
int FILTER_LIST[LIST_LENGTH];
int MAX_LIST[LIST_LENGTH];
int MIN_LIST[LIST_LENGTH];

void EM_FILTER_INIT(){
    int index;
    times = 0;
    for(index = 0 ; index<LIST_LENGTH ; index++){
        FILTER_LIST[index] = 0;
        MAX_LIST[index] = EM_MAX;
        MIN_LIST[index] = EM_MIN;
    }
}

void EM_FILTER_ADD_SAMPLE(int* DATA_SAMPLE_LIST){
    int index,temp;
    for(index=0;index<LIST_LENGTH;index++){
        temp = DATA_SAMPLE_LIST[index];
        MAX_LIST[index] = MAX_LIST[index]<temp ? temp : MAX_LIST[index];
        MIN_LIST[index] = MIN_LIST[index]>temp ? temp : MIN_LIST[index];
        FILTER_LIST[index] += temp;
    }
    times++;
}

void EM_FILTER_READ_RESULT(int* RES_SET){
    int index;
    for(index=0;index<LIST_LENGTH;index++){
        if(times>=3)
            RES_SET[index] = (FILTER_LIST[index]-MAX_LIST[index]-MIN_LIST[index])/(times-2);
        else
            RES_SET[index] = FILTER_LIST[index];
    }
    EM_FILTER_INIT();
}