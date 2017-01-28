#include "mytask.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include "myclass.h"

/*
 * To use classes the source must be of .cpp type
 * since the freertos.c should maintain the type (because of CubeMX)
 * we place the task in a .cpp file
 */

void StartPrintTask(void const * argument)
{
	int n = 0;
	MyClass xxx;

  for(;;)
  {
    HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
  	printf("%d\r\n", n);
  	n = xxx.incby(n, 2);
    osDelay(1000);
  }
}
