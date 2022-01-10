#include "HEADFILE.h"
#include "SEEKFREE_18TFT.h"
#include "SEEKFREE_FONT.h"

void SYS_INIT_ALL(){
    BOARD_INIT();
	DELAY_INIT();
    EXINT_ADDRESS_INIT();
    TIMER_ADDRESS_INIT();
    IQR_Enable_ALL();
    TASK_INIT_TASKSYS();  //多任务系统,开启则占用定时器TIMER0
}

void main(){
    SYS_INIT_ALL();
    lcd_init();
    while(1){
        lcd_clear(WHITE);
        lcd_showchar(1,1,'a');  
    }
}