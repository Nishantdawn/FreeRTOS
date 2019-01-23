#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "stm32l1xx.h"
#include "discover_board.h"

static void my_task( void *arg )
{
while(1)
{
GPIO_HIGH( LD_GPIO_PORT, LD_GREEN_GPIO_PIN );
vTaskDelay(100);
GPIO_LOW( LD_GPIO_PORT, LD_GREEN_GPIO_PIN );
vTaskDelay(100);
}
}

void main_low_power( void )
{
xTaskCreate(my_task,(char*)"my_task",1024,NULL,1,NULL);
vTaskStartScheduler();
while(1);
}
