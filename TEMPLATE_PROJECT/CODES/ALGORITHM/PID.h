/*
 * @Description  : PID控制算法封装
 * @Author       : FZU Liao
 * @Date         : 2022-01-02 20:19:26
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-02 22:00:35
 * @FilePath     : \ALGORITHM\PID.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __PID_H__
#define __PID_H__

typedef enum{
    PID_REALIZE_MODE,
    PID_INCREASE_MODE
}PID_CONTROL_MODE;

struct PID_CONTROL_STRUCT{
    
    PID_CONTROL_MODE PID_X_MODE;    //PID工作模式

    float FACTOR_Proportional;      //比例系数
    float FACTOR_Integral;          //积分系数
    float FACTOR_Differential;      //微分系数
    
    float TARGET_VALUE;             //目标值
    
    float PID_CURRENT_ERROR;        //当前误差记录
    float PID_LAST_ERROR;           //前一次误差记录
    float PID_SUM_ERROR;            //误差积分
    
};

typedef struct PID_CONTROL_STRUCT* PID;

/**
 * @description:             初始化PID算法
 * @param NEW_PID PID        未初始化过的PID控制算法
 * @param Param_P float      比例系数P
 * @param Param_I float      积分系数I
 * @param Param_D float      微分系数D
 * @param Param_Target float PID控制的目标值
 * @return NULL
 * @example: NULL
 */
void PID_INIT_NEWPID(PID NEW_PID,float Param_P,float Param_I,float Param_D,float Param_Target,PID_CONTROL_MODE PID_MODE);

/**
 * @description:              为PID算法设定目标值
 * @param PID_CONTROL PID     PID算法
 * @param Param_Target float  目标值
 * @return NULL
 * @example: NULL
 */
void PID_SET_TARGET(PID PID_CONTROL,float Param_Target);

/**
 * @description:            设置PID算法系数
 * @param PID_CONTROL PID   PID算法
 * @param Param_P float     比例系数P
 * @param Param_I float     积分系数I
 * @param Param_D float     微分系数D
 * @return *
 * @example: 
 */
void PID_SET_FACTORS(PID PID_CONTROL,float Param_P,float Param_I,float Param_D);

/**
 * @description:                计算PID控制算法结果并返回
 * @param PID_CONTROL PID       PID算法
 * @param CURRENT_INPUT float   当前输入
 * @return PID_OUTPUT           PID算法的结果
 * @example: NULL
 */
float PID_CLAC_RESULT(PID PID_CONTROL,float CURRENT_INPUT);

/**
 * @description:            逆初始化PID算法
 * @param PID_CONTROL PID   PID算法
 * @return NULL
 * @example: NULL
 */
void PID_DEINIT_PID(PID PID_CONTROL);

#endif