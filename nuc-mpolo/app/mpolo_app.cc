#include "mpolo_app.h"

#include <cstdio>

__IO uint32_t kBspButtonState = BUTTON_RELEASED;

extern "C" void MpoloDefaultTask() {
  std::printf("Mpolo.ai App Starting..\n\r");
  while (true) {
    // if (kBspButtonState == BUTTON_PRESSED) {
    // BSP_LED_On(LED_GREEN);
    // // kBspButtonState = BUTTON_RELEASED;
    // // }
    // HAL_Delay(1000);
    // BSP_LED_Off(LED_GREEN);
    // HAL_Delay(1000);
  }
}
