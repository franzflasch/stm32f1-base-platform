/* STM32F103RB with FreeRTOS
 */

#include <stm32f10x.h>
#include <stm32f10x_conf.h>
#include <stm32_configuration.h>
#include <helperFunctions.h>
#include <math.h>

#include <main.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include <FreeRTOSConfig.h>

/* Application specific declarations */
char UartBuffer[UART_BUF_LEN];
AppWa_t applicationData;

static void LedToggleTask( void *pvParameters );

int main()
{
	  RCC_Configuration();
	  NVIC_Configuration();
	  GPIO_Configuration();

	  /* UART initialization */
	  UART_init(&applicationData.uartInfo, &UartBuffer[0], UART_BUF_LEN);
	  USART_Configuration();

	  /*Short delay to be sure everything is properly initialized*/
	  Delay(10000);

	  xTaskCreate( LedToggleTask, ( signed char * ) "LedToggle", configMINIMAL_STACK_SIZE, NULL, 3, NULL );
	  vTaskStartScheduler();

	  /* For debug-purposes*/
	  printf(" Start%d\n",0);

	  while(1)
	  {
	  }
}


static void LedToggleTask( void *pvParameters )
{
	portTickType xNextWakeTime;
	uint32_t i = 0;

	xNextWakeTime = xTaskGetTickCount();

	for( ;; )
	{
		//printf(" Cnt: %u\n\r", i++);
		GPIOC->ODR ^= GPIO_Pin_12;
		vTaskDelayUntil( &xNextWakeTime, 1000 );
	}
}



void vApplicationMallocFailedHook( void )
{
	/* Called if a call to pvPortMalloc() fails because there is insufficient
	free memory available in the FreeRTOS heap.  pvPortMalloc() is called
	internally by FreeRTOS API functions that create tasks, queues, software
	timers, and semaphores.  The size of the FreeRTOS heap is set by the
	configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configconfigCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{

	/* This function is called on each cycle of the idle task.  In this case it
	does nothing useful, other than report the amout of FreeRTOS heap that
	remains unallocated. */

}


void vApplicationTickHook( void )
{


}
