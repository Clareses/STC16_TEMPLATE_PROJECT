/*
 * @Description  : 滤波算法，采取去除一个最高值、一个最低值后再取平均的方式
 * @Author       : FZU Liao
 * @Date         : 2022-01-08 18:23:36
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-08 18:45:33
 * @FilePath     : \TEMPLATE_PROJECT\CODES\ALGORITHM\EM_FILTER.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __EM_FILTER_H__
#define __EM_FILTER_C__

/**
 * @description: 初始化滤波器
 * @param *
 * @return *
 * @example: 
 */
void EM_FILTER_INIT();

/**
 * @description: 数据样本列表
 * @param DATA_SAMPLE_LIST int*
 * @return *
 * @example: 
 */
void EM_FILTER_ADD_SAMPLE(int* DATA_SAMPLE_LIST);

/**
 * @description: 返回计算结果
 * @param RES_SET int* 存储结果的数组
 * @return
 * @example: 
 */
void EM_FILTER_READ_RESULT(int* RES_SET);
#endif