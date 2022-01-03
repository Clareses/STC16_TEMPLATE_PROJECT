/*
 * @Description  : 任务系统实现
 * @Author       : FZU Liao
 * @Date         : 2022-01-01 21:20:45
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-03 11:23:59
 * @FilePath     : \BOARD\TASK.c
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#include "TIMER.h"
#include "TASK.h"

struct TASK* TaskList[TASK_MAX_N];

void Task_Excute(struct TASK* task){
    if(task == 0) return;
    task->COUNTER++;
    task->COUNTER%=task->THRESHOLD;
    if(task->COUNTER==task->THRESHOLD-1) (*task->FUNC)();
}

void TASK_STATE_UPDATE(){
    int i;
    for(i=0;i<TASK_MAX_N;i++){
        Task_Excute(TaskList[i]);
    }
}

void TASK_INIT_TASKSYS(){
    TIMER_ADDRESS_INIT();
    TIMER_INIT_TIMERx(Timer0,1,T,1,0,TASK_STATE_UPDATE);
    TIMER_ENABLE(Timer0);
}

void TASK_INIT_NEWTASK(struct TASK* task,uint16 Threshold,void (*func)()){
    //memset(task,0,sizeof(task));
    task->COUNTER = 0;
    task->THRESHOLD = Threshold;
    task->FUNC = func;
}

void TASK_SETID(uint8 ID,struct TASK* task){
    task->ID=ID;
}

void TASK_SETFUNC(void (*func)(),struct TASK* task){
    task->FUNC=func;
}

void TASK_ADD_TASK(struct TASK* task){
    int i;
    for (i = 0; i < TASK_MAX_N; i++) {
        if(TaskList[i]==0){
            TaskList[i]=task;
            TASK_SETID(i,task);
            return ;
        }
    }
}

void TASK_DELETE_TASK(struct TASK* task){
    TaskList[task->ID]=0;
}

void TASK_PAUSE_TASKSYS(){
    TIMER_DISABLE(Timer0);
}

void TASK_DEINIT_TASKSYS(){
    int i;
    for (i = 0; i < TASK_MAX_N; i++) {
        TaskList[i] = 0;
    }
    TIMER_DISABLE(Timer0);
}

