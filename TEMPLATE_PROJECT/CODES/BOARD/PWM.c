/*
 * @Description  : PWM输出的具体实现
 * @Author       : FZU Liao
 * @Date         : 2021-12-31 19:34:13
 * @LastEditors  : Liao
 * @LastEditTime : 2022-01-10 09:26:07
 * @FilePath     : \TEMPLATE_PROJECT\CODES\BOARD\PWM.c
 * Copyright 2021 FZU Liao, All Rights Reserved. 
 */

#include "PWM.h"

const uint32 PWM_CCMR_ADDR[] = {0x7efec8, 0x7efec9, 0x7efeca ,0x7efecb,
                                0x7efee8, 0x7efee9, 0x7efeea, 0x7efeeb};
const uint32  PWM_CCR_ADDR[] = {0x7efed5, 0x7efed7, 0x7efed9, 0x7efedb,
							    0x7efef5, 0x7efef7, 0x7efef9, 0x7efefb};
const uint32 PWM_CCER_ADDR[] = {0x7efecc, 0x7efecd, 0x7efeec ,0x7efeed};
const uint32  PWM_ARR_ADDR[] = {0x7efed2,0x7efef2};

void PWM_INIT_PWMCHANNEL(PWM_CHANNEL_enum PWMn_CHx_Pin,uint32 Frequecy, uint16 Duty){
	if(Duty>10000) Duty = 10000;	//限幅
	uint16 DUTY_RATIO;              //占空比
	uint16 CYCLE_TIME;              //周期
	uint16 FREQUENCY_DIVIDER = 0;   //分频

    P_SW2 |= 0x80;

	if(Frequecy>500){
		FREQUENCY_DIVIDER = (SYS_CLK / Frequecy) >> 16;
		CYCLE_TIME = SYS_CLK / Frequecy;			
		CYCLE_TIME = CYCLE_TIME / (FREQUENCY_DIVIDER + 1) - 1;
	}else{
		FREQUENCY_DIVIDER = (SYS_CLK/Frequecy/PWM_MAX_DUTY) - 1;
		CYCLE_TIME = PWM_MAX_DUTY;			
	}

	DUTY_RATIO = CYCLE_TIME * ((float)Duty/PWM_MAX_DUTY);
    //PWMB配置
	if(PWMB_CH1_P20 <= PWMn_CHx_Pin){
		PWM2_ENO |= (1 << ((2 * ((PWMn_CHx_Pin >> 4) - 4))));
		PWM2_PS |= ((PWMn_CHx_Pin & 0x03) << ((2 * ((PWMn_CHx_Pin >> 4) - 4))));

		(*(unsigned char volatile far*)(PWM_CCER_ADDR[PWMn_CHx_Pin>>5]))|=(uint8)(1<<(((PWMn_CHx_Pin>>4)&0x01)*4));

		PWM2_PSCRH = (uint8)(FREQUENCY_DIVIDER>>8);
		PWM2_PSCRL = (uint8)FREQUENCY_DIVIDER;

	}
    //PWMA配置
	else{
		PWM1_ENO |= (1 << (PWMn_CHx_Pin & 0x01)) << ((PWMn_CHx_Pin >> 4) * 2);	
		PWM1_PS  |= ((PWMn_CHx_Pin & 0x07) >> 1) << ((PWMn_CHx_Pin >> 4) * 2); 
		(*(unsigned char volatile far *) (PWM_CCER_ADDR[PWMn_CHx_Pin>>5])) 
			|= (1 << ((PWMn_CHx_Pin & 0x01) * 2 + ((PWMn_CHx_Pin >> 4) & 0x01) * 0x04));
		PWM1_PSCRH = (uint8)(FREQUENCY_DIVIDER>>8);
		PWM1_PSCRL = (uint8)FREQUENCY_DIVIDER;
	}
	
	(*(unsigned char volatile far *) (PWM_ARR_ADDR[PWMn_CHx_Pin>>6]))       = (uint8)(CYCLE_TIME>>8);
	(*(unsigned char volatile far *) (PWM_ARR_ADDR[PWMn_CHx_Pin>>6] + 1))   = (uint8)CYCLE_TIME;

	(*(unsigned char volatile far *) (PWM_CCR_ADDR[PWMn_CHx_Pin>>4]))		= DUTY_RATIO>>8;
	(*(unsigned char volatile far *) (PWM_CCR_ADDR[PWMn_CHx_Pin>>4] + 1))  = (uint8)DUTY_RATIO;
	
	(*(unsigned char volatile far *) (PWM_CCMR_ADDR[PWMn_CHx_Pin>>4])) |= 0x06<<4;
	(*(unsigned char volatile far *) (PWM_CCMR_ADDR[PWMn_CHx_Pin>>4])) |= 1<<3;
}

void PWM_SET_DUTY(PWM_CHANNEL_enum PWMn_CHx_Pin,uint16 Duty){
	if(Duty>10000) Duty=10000;
    uint16 DUTY_RATIO;
	uint16 ARR = ((*(unsigned char volatile far *) (PWM_ARR_ADDR[PWMn_CHx_Pin>>6]))<<8) 
                 |(*(unsigned char volatile far *) (PWM_ARR_ADDR[PWMn_CHx_Pin>>6] + 1 ));
	DUTY_RATIO = ARR * ((float)Duty/PWM_MAX_DUTY);
	(*(unsigned char volatile far *) (PWM_CCR_ADDR[PWMn_CHx_Pin>>4]))	  = DUTY_RATIO>>8;	
	(*(unsigned char volatile far *) (PWM_CCR_ADDR[PWMn_CHx_Pin>>4] + 1)) = (uint8)DUTY_RATIO;
	PWM_ENABLE(PWMn_CHx_Pin);
}


void PWM_ENABLE(PWM_CHANNEL_enum PWMn_CHx_Pin){
    if(PWMB_CH1_P20 <= PWMn_CHx_Pin){
        PWM2_BKR |= 0x80;
        PWM2_CR1 |= 0x01;
    }else{
        PWM1_BKR |= 0x80;
        PWM1_CR1 |= 0x01;
    }
}

void PWM_DISABLE(PWM_CHANNEL_enum PWMn_CHx_Pin){
    if(PWMB_CH1_P20 <= PWMn_CHx_Pin){
        PWM2_BKR &= 0x7F;
        PWM2_CR1 &= 0xFE;
    }else{
        PWM1_BKR &= 0x7F;
        PWM1_CR1 &= 0xFE;
    }
}
