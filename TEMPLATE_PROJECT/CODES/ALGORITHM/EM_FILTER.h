/*
 * @Description  : 滤波器定义
 * @Author       : FZU Liao
 * @Date         : 2022-01-08 21:03:05
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-08 21:07:23
 * @FilePath     : \TEMPLATE_PROJECT\CODES\ALGORITHM\EM_FILTER.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

//滤波可以采取以下方式
//传入n次样本（通过参数传递进来），去除最大值和最小值，再对剩余的取平均

//初始化
void EM_FILTER_INIT();

//添加一次样本
void EM_FILTER_ADD_SAMPLE(int* SAMPLE_DATA_LIST);

//对添加过的样本作计算返回后再清空已经记录的值
void EM_FILTER_READ_RES(int* RES_SET);