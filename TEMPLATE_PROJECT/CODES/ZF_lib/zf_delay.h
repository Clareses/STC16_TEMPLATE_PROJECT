/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 *
 * @file       		zfdelay
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC16F40K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-4-14
 ********************************************************************************************************************/

#ifndef __ZF_zfdelay_H
#define __ZF_zfdelay_H
#include "common.h"


void zfdelay_init();
void zfdelay_ms(uint16 x);
void zfdelay_us(uint32 us);



#endif
