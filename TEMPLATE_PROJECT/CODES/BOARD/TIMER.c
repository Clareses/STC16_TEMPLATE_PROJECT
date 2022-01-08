#include "TIMER.h"

struct TIMER_NORMAL_TYPE TIMER_NORMAL_list[5];
struct TIMER_T01_TYPE TIMER_T01_list[2];
struct TIMER_T34_TYPE TIMER_T34_list[2];

void TIMER_ADDRESS_INIT(){
    TIMER_NORMAL_list[0].TIMER_ID       = 0;
    TIMER_NORMAL_list[0].ENABLE_bit     = 0x10;
    TIMER_NORMAL_list[0].F_Divider_bit  = 0x80;
    TIMER_NORMAL_list[0].TorC_bit       = 0x04;
    TIMER_NORMAL_list[0].TnCLKO_bit     = 0x01; 
    TIMER_NORMAL_list[0].TIMER_INT_FUNC = 0;

    TIMER_NORMAL_list[1].TIMER_ID       = 1;
    TIMER_NORMAL_list[1].ENABLE_bit     = 0x40;
    TIMER_NORMAL_list[1].F_Divider_bit  = 0x40;
    TIMER_NORMAL_list[1].TorC_bit       = 0x40;
    TIMER_NORMAL_list[1].TnCLKO_bit     = 0x02; 
    TIMER_NORMAL_list[1].TIMER_INT_FUNC = 0;

    TIMER_NORMAL_list[2].TIMER_ID       = 2;
    TIMER_NORMAL_list[2].ENABLE_bit     = 0x10;
    TIMER_NORMAL_list[2].F_Divider_bit  = 0x04;
    TIMER_NORMAL_list[2].TorC_bit       = 0x08;
    TIMER_NORMAL_list[2].TnCLKO_bit     = 0x04; 
    TIMER_NORMAL_list[2].TIMER_INT_FUNC = 0;

    TIMER_NORMAL_list[3].TIMER_ID       = 3;
    TIMER_NORMAL_list[3].ENABLE_bit     = 0x08;
    TIMER_NORMAL_list[3].F_Divider_bit  = 0x02;
    TIMER_NORMAL_list[3].TorC_bit       = 0x04;
    TIMER_NORMAL_list[3].TnCLKO_bit     = 0x01; 
    TIMER_NORMAL_list[3].TIMER_INT_FUNC = 0;

    TIMER_NORMAL_list[4].TIMER_ID       = 4;
    TIMER_NORMAL_list[4].ENABLE_bit     = 0x80;
    TIMER_NORMAL_list[4].F_Divider_bit  = 0x20;
    TIMER_NORMAL_list[4].TorC_bit       = 0x40;
    TIMER_NORMAL_list[4].TnCLKO_bit     = 0x10;
    TIMER_NORMAL_list[4].TIMER_INT_FUNC = 0;

    TIMER_T01_list[0].TIMER_NORMAL      =&TIMER_NORMAL_list[0];
    TIMER_T01_list[1].TIMER_NORMAL      =&TIMER_NORMAL_list[1];
    TIMER_T01_list[0].M0_bit            =0x01;
    TIMER_T01_list[0].M1_bit            =0x02;
    TIMER_T01_list[1].M0_bit            =0x10;
    TIMER_T01_list[1].M1_bit            =0x20;

    TIMER_T34_list[0].TIMER_NORMAL      =&TIMER_NORMAL_list[3];
    TIMER_T34_list[1].TIMER_NORMAL      =&TIMER_NORMAL_list[4];
    TIMER_T34_list[0].Pin_choose_bit    =0x01;
    TIMER_T34_list[1].Pin_choose_bit    =0x01;

    IE  |= 0x0A;
    IE2 |= 0x64;
}

void TIMER_SET_TIMES(TIMER_enum Timerx,TIMER_COUNTER_enum TorC,uint16 times){
    uint16 temp;
    if(TorC==T){
        temp = 65536-((SYS_CLK/1000)/12)*times;
    }else{
        temp = 65536 - times;
    }
    switch (Timerx){
    case 0:
        TL0 = temp%256;
        TH0 = temp>>8;
        break;
    case 1:
        TL1 = temp%256;
        TH1 = temp>>8;
        break;
    case 2:
        T2L = temp%256;
        T2H = temp>>8;
        break;
    case 3:
        T3L = temp%256;
        T3H = temp>>8;
        break;
    case 4:
        T4L = temp%256;
        T4H = temp>>8;
        break;    
    default:
        break;
    }
}

void TIMER_INIT_TIMERx(TIMER_enum Timerx,TIMER_COUNTER_enum TorC,uint32 times,uint8 F_Div,uint8 is_CLKOUT,void (*func)()){
    if(Timerx<=1){
        TMOD    &= ~(TIMER_NORMAL_list[Timerx].TorC_bit);
        AUXR    &= ~(TIMER_NORMAL_list[Timerx].F_Divider_bit);
        INTCLKO &= ~(TIMER_NORMAL_list[Timerx].TnCLKO_bit);
        TMOD    |= ((TIMER_NORMAL_list[Timerx].TorC_bit)*TorC);
        AUXR    |= ((TIMER_NORMAL_list[Timerx].F_Divider_bit)*F_Div);
        INTCLKO |= ((TIMER_NORMAL_list[Timerx].TnCLKO_bit)*is_CLKOUT);
    }else if(Timerx==2){
        AUXR    &= ~(TIMER_NORMAL_list[Timerx].F_Divider_bit|TIMER_NORMAL_list[Timerx].TorC_bit);
        INTCLKO &= ~(TIMER_NORMAL_list[Timerx].TnCLKO_bit);
        AUXR |= (
            (TIMER_NORMAL_list[Timerx].F_Divider_bit*F_Div) |
            (TIMER_NORMAL_list[Timerx].TorC_bit*TorC)      
        );
        INTCLKO |= ((TIMER_NORMAL_list[Timerx].TnCLKO_bit)*is_CLKOUT);
    }else{
        T4T3M &= ~(
            TIMER_NORMAL_list[Timerx].TorC_bit      |
            TIMER_NORMAL_list[Timerx].F_Divider_bit |
            TIMER_NORMAL_list[Timerx].TnCLKO_bit
        );
        T4T3M |= (
            TIMER_NORMAL_list[Timerx].TorC_bit*TorC         |
            TIMER_NORMAL_list[Timerx].F_Divider_bit*F_Div   |
            TIMER_NORMAL_list[Timerx].TnCLKO_bit*is_CLKOUT
        );
    }
    TIMER_SET_TIMES(Timerx,TorC,times);
}

void TIMER_T01_SETMODE(TIMER_enum Timerx,T01_MODE_enum Mode){
    TMOD &= ~(Mode<<(Timerx*4));
    TMOD |=  (Mode<<(Timerx*4));
}


void TIMER_T34_SETPIN(TIMER_enum Timerx,T34_PIN_enum Pin_Mode){
    
}

void TIMER_ENABLE(TIMER_enum Timerx){
    if(Timerx<=1){
        TCON |= TIMER_NORMAL_list[Timerx].ENABLE_bit;
    }else if(Timerx==2){
        AUXR |= TIMER_NORMAL_list[Timerx].ENABLE_bit;
    }else{
        T4T3M|= TIMER_NORMAL_list[Timerx].ENABLE_bit;
    }
}

void TIMER_DISABLE(TIMER_enum Timerx){
    if(Timerx<=1){
        TCON &= ~TIMER_NORMAL_list[Timerx].ENABLE_bit;
    }else if(Timerx==2){
        AUXR &= ~TIMER_NORMAL_list[Timerx].ENABLE_bit;
    }else{
        T4T3M&= ~TIMER_NORMAL_list[Timerx].ENABLE_bit;
    }
}

void TIMER_SET_TIMERFUNC(TIMER_enum Timerx,void (*func)()){
    TIMER_NORMAL_list[Timerx].TIMER_INT_FUNC=func;
}

uint32 TIMER_READ_COUNTER(TIMER_enum Timerx){
    uint32 RES;
    RES = 0x00;
    switch (Timerx){
    case 0:
        RES |= TL0;
        RES |= TH0<<8;
        break;
    case 1:
        RES |= TL1;
        RES |= TH1<<8;
        break;
    case 2:
        RES |= T2L;
        RES |= T2H<<8;
        break;
    case 3:
        RES |= T3L;
        RES |= T3H<<8;
        break;
    case 4:
        RES |= T4L;
        RES |= T4H<<8;
        break;    
    default:
        break;
    }
}

void TIMER_CLEAN_COUNTER(TIMER_enum Timerx){
    switch (Timerx){
    case 0:
        TL0 = 0x00;
        TH0 = 0x00;
        break;
    case 1:
        TL1 = 0x00;
        TH1 = 0x00;
        break;
    case 2:
        T2L = 0x00;
        T2H = 0x00;
        break;
    case 3:
        T3L = 0x00;
        T3H = 0x00;
        break;
    case 4:
        T4L = 0x00;
        T4H = 0x00;
        break;    
    default:
        break;
    }
}

void TIMER0_Routine() interrupt 1
{
    if(TIMER_NORMAL_list[0].TIMER_INT_FUNC!=0) (*TIMER_NORMAL_list[0].TIMER_INT_FUNC)();
}

void TIMER1_Routine() interrupt 3
{
    if(TIMER_NORMAL_list[1].TIMER_INT_FUNC!=0) (*TIMER_NORMAL_list[1].TIMER_INT_FUNC)();
}

void TIMER2_Routine() interrupt 12
{
    if(TIMER_NORMAL_list[2].TIMER_INT_FUNC!=0) (*TIMER_NORMAL_list[2].TIMER_INT_FUNC)();
}

void TIMER3_Routine() interrupt 19
{
    if(TIMER_NORMAL_list[3].TIMER_INT_FUNC!=0) (*TIMER_NORMAL_list[3].TIMER_INT_FUNC)();
}

void TIMER4_Routine() interrupt 20
{
    if(TIMER_NORMAL_list[4].TIMER_INT_FUNC!=0) (*TIMER_NORMAL_list[4].TIMER_INT_FUNC)();
}