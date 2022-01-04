/*
 * @Description  : 多任务封装
 * @Author       : FZU Liao
 * @Date         : 2022-01-01 21:20:35
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-04 23:02:20
 * @FilePath     : \TEMPLATE_PROJECT\CODES\BOARD\TASK.h
 * @note         : 若使用多任务，则默认TIEMR0作为系统时钟，不可再进行修改
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __TASK_H__
#define __TASK_H__

#include "COMMON.h"

#define TASK_MAX_N 4

typedef struct Task{
    uint16 COUNTER;
    uint16 THRESHOLD;
    void (*FUNC)();
    uint8 ID;
};

typedef struct Task TASK;

/**
 * @description: 初始化任务系统,包括TIMER0初始化等
 * @param NULL
 * @return NULL
 * @warning 初始化任务系统后，TIMER0将作为系统时钟而不再用于用户调整
 */
void TASK_INIT_TASKSYS();

/**
 * @description: 初始化一个新任务
 * @param task Task* 任务指针
 * @param Threshold uint16 任务执行间隔时间，Threshold = x 意味每x ms执行一次
 * @param func 无参无返回值函数
 * @return *
 * @example: 
 */
void TASK_INIT_NEWTASK(TASK* task,uint16 Threshold,void (*func)());

/**
 * @description: 设置/修改任务函数
 * @param func void无参函数
 * @param task Task*
 * @return *
 * @example: 
 */
void TASK_SETFUNC(void (*func)(),TASK* task);

/**
 * @description: 向任务系统中添加任务
 * @param task Task* 任务指针
 * @return *
 * @example: 
 */
void TASK_ADD_TASK(TASK* task);

/**
 * @description: 从任务系统中删除任务
 * @param task Task* 任务指针
 * @return *
 * @example: 
 */
void TASK_DELETE_TASK(TASK* task);

/**
 * @description: 暂停任务系统
 * @param *
 * @return *
 * @example: 
 */
void TASK_PAUSE_TASKSYS();

/**
 * @description: 逆初始化任务系统
 * @param *
 * @return *
 * @example: 
 */
void TASK_DEINIT_TASKSYS();


#endif