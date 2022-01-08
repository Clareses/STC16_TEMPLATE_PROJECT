#include "HEADFILE.h"
#include "MyControlSys.h"

void SYS_INIT_ALL(){
	DELAY_INIT();
    EXINT_ADDRESS_INIT();
    TIMER_ADDRESS_INIT();
    IQR_Enable_ALL();
    TASK_INIT_TASKSYS();  //多任务系统,开启则占用定时器TIMER0
}

//UserCode-------------------------------------------------------------------------------------------



//UserCode-------------------------------------------------------------------------------------------

void main(){
    SYS_INIT_ALL();
    MySYS_INIT();
    //UserCode---------------------------------------------------------------------------------------
	TASK My_CAR_Routine;
    TASK_INIT_NEWTASK(&My_CAR_Routine,1,My_routineTask);
    TASK_ADD_TASK(&My_CAR_Routine);
    //UserCode---------------------------------------------------------------------------------------
}