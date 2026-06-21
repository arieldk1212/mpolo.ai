#ifndef MPOLO_APP_H_
#define MPOLO_APP_H_

#include "stm32g4xx_nucleo.h"

#ifdef __cplusplus
extern "C" {
#endif

extern __IO uint32_t kBspButtonState;

void MpoloApp();

#ifdef __cplusplus
}
#endif

#endif
