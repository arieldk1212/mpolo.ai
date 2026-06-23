#ifndef MPOLO_APP_H_
#define MPOLO_APP_H_

#include "stm32g4xx_nucleo.h"

#ifdef __cplusplus
extern "C" {
#endif

extern __IO uint32_t kBspButtonState;

void MpoloMainTask();

void MpoloApp(void* arguments);

#ifdef __cplusplus
}
#endif

#endif
