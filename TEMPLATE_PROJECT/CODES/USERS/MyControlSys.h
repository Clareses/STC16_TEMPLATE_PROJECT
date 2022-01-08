/*
 * @Description  : 总控制系统，负责信号采集、电机输出等配置
 * @Author       : FZU Liao
 * @Date         : 2022-01-06 16:58:07
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-08 21:55:39
 * @FilePath     : \TEMPLATE_PROJECT\CODES\USERS\MyControlSys.h
 * Copyright 2022 FZU Liao, All Rights Reserved. 
 */

#ifndef __CONTROL_SYS__
#define __CONTROL_SYS__

#include "HEADFILE.h"
#include "MyStepMotorControl.h"
#include "MyStreeringControl.h"
#include "MyStreeringAdapter.h"
#include "MyStepMotorPIDAdapter.h"
#include "EM_SENSOR.h"
#include "ENCODE_SENSOR.h"
#include "EM_FILTER.h"

int EM_DATA_LIST[4];

void MySYS_INIT(){
    //初始化两个电机、信号采集系统等
    EM_INIT_SENSOR();
    ENCODING_INIT(TIMER1_P35);
    MySTEPMOTOR_PID_INIT();
    MyStepMotor_INIT();
}

void My_routineTask(){
    int ANGLE,TARGET_SPEED,CURRENT_SPEED,index;
    //调用电磁传感器，获取数据并滤波
    for(index=0;index<6;index++){
        EM_READ_SENSOR(EM_DATA_LIST);
        EM_FILTER_ADD_SAMPLE(EM_DATA_LIST);
    }
    EM_FILTER_READ_RESULT(EM_DATA_LIST);
    //滤波结束后的值，进行处理，数据传给舵机控制系统控制舵机，并接收一个返回值（舵机打角的角度）
    {
        ANGLE = Streering_Control(EM_DATA_LIST);
    }
    //读取计数器，处理
    {
        CURRENT_SPEED = ENCODING_READ_RESULT(TIMER1_P35);
    }
    //利用舵机打角角度，处理出速度目标值
    {
        //计算过程
    }
    //传两个值给电机控制系统（一个当前值，一个目标值）
    {
        StepMotor_Control(CURRENT_SPEED,TARGET_SPEED);
    }
}

#endif