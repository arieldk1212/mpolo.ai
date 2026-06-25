#ifndef MPOLO_APP_H_
#define MPOLO_APP_H_

#include "cmsis_os2.h"
#include "stm32g4xx_nucleo.h"

#ifdef __cplusplus
extern "C" {
#endif

extern __IO uint32_t kBspButtonState;

extern osThreadId_t kMpoloDefaultTaskHandle;
static const osThreadAttr_t kMpoloDefaultTaskAttributes = {
    .name = "MpoloDefaultTask",
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityNormal,
};

void MpoloDefaultTask(void* arguments);

#ifdef __cplusplus
}
#endif

#endif
