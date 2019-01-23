#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"


static void my_task( void *arg )
{
	while(1)
{
printf("Hello World!\n");
vTaskDelay(1000);
}
}

void main_blinky( void )
{							
xTaskCreate(my_task,(char*)"my_task",1024,NULL,1,NULL);
vTaskStartScheduler();
}
