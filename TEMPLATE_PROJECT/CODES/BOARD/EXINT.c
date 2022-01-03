/*
 * @Description  : 外部中断封装实现
 * @Author       : FZU Liao
 * @Date         : 2021-12-28 22:26:02
 * @LastEditors  : Liao
 * @LastEditTime : 2021-12-31 12:52:57
 * @FilePath     : \EXINT\EXINT.c
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#include "EXINT.h"

#define ENABLE_REGISTER0 IE
#define ENABLE_REGISTER1 INTCLKO

//外部中断结构体定义
struct EXINT_TYPE{
    uint8 ENABLE_offset;
    void (*EXINT_FUNC)();
};

struct EXINT_TYPE EXINT_list[5];

void EXINT_ADDRESS_INIT(){
    EXINT_list[0].ENABLE_offset=0;
    EXINT_list[1].ENABLE_offset=2;
    EXINT_list[2].ENABLE_offset=4;
    EXINT_list[3].ENABLE_offset=5;
    EXINT_list[4].ENABLE_offset=6;
    EXINT_list[0].EXINT_FUNC=0;
    EXINT_list[1].EXINT_FUNC=0;
    EXINT_list[2].EXINT_FUNC=0;
    EXINT_list[3].EXINT_FUNC=0;
    EXINT_list[4].EXINT_FUNC=0;
}

void EXINT_INIT(EXINTn_enum EXINTn,void (*func)(),EXINT_MODE_enum EXT_mode){
    if(EXINTn==0) IT0=EXT_mode;
    if(EXINTn==1) IT1=EXT_mode;
    EXINT_SET_FUNC(EXINTn,func);
}

void EXINT_SET_FUNC(EXINTn_enum EXINTn,void (*func)()){
    EXINT_list[EXINTn].EXINT_FUNC=func;
}

void EXINT_ENABLE(EXINTn_enum EXINTn){
    if(EXINTn<=1) 
        ENABLE_REGISTER0 |= (0x01<<EXINT_list[EXINTn].ENABLE_offset);
    else 
        ENABLE_REGISTER1 |= (0x01<<EXINT_list[EXINTn].ENABLE_offset);
}

void EXINT_DISABLE(EXINTn_enum EXINTn){
    if(EXINTn<=1) 
        ENABLE_REGISTER0 &= ~(0x01<<EXINT_list[EXINTn].ENABLE_offset);
    else
        ENABLE_REGISTER1 &= ~(0x01<<EXINT_list[EXINTn].ENABLE_offset);
}

void EXT0_Routine() interrupt 0
{
    if(EXINT_list[0].EXINT_FUNC!=0)
        (*EXINT_list[0].EXINT_FUNC)();
    EXT0_CLEAR_FLAG;
}

void EXT1_Routine() interrupt 2
{
    if(EXINT_list[1].EXINT_FUNC!=0)
        (*EXINT_list[1].EXINT_FUNC)();
    EXT1_CLEAR_FLAG;
}

void EXT2_Routine() interrupt 10
{
    if(EXINT_list[2].EXINT_FUNC!=0)
        (*EXINT_list[2].EXINT_FUNC)();
    EXT2_CLEAR_FLAG;
}

void EXT3_Routine() interrupt 11
{
    if(EXINT_list[3].EXINT_FUNC!=0)
        (*EXINT_list[3].EXINT_FUNC)();
    EXT3_CLEAR_FLAG;
}

void EXT4_Routine() interrupt 16
{
    if(EXINT_list[4].EXINT_FUNC!=0)
        (*EXINT_list[4].EXINT_FUNC)();
    EXT4_CLEAR_FLAG;
}
