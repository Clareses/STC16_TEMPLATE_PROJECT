/*
 * @Description  : 差和比差加权算法实现
 * @Author       : FZU Liao
 * @Date         : 2022-01-10 12:39:00
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-10 12:44:08
 * @FilePath     : \TEMPLATE_PROJECT\CODES\ALGORITHM\EM_Calc.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#include "EM_Calc.h"

float EM_CACL_POS_RES(int* data){
    float RES;
    RES = data[LM]-data[RM] > 0?
    (
        ((float)(data[L]-data[R])*ParamA + (float)(data[LM]-data[RM])*ParamB)
       /((float)(data[L]+data[R])*ParamA + (float)(data[LM]-data[RM])*ParamB)
    ):(
        ((float)(data[L]-data[R])*ParamA + (float)(data[LM]-data[RM])*ParamB)
       /((float)(data[L]+data[R])*ParamA + (float)(data[RM]-data[LM])*ParamB)
    );
    return RES;
}