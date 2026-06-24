#include "mpolo_app.h"

#include <cstdio>

#include "uart/mpolo_uart.h"

__IO uint32_t kBspButtonState = BUTTON_RELEASED;

void MpoloMain() {
  mpolo::uart::Transmit();
}

extern "C" void MpoloDefaultTask() {
  std::printf("Mpolo.ai App Starting..\n\r");
  while (true) {
    MpoloMain();
    // if (kBspButtonState == BUTTON_PRESSED) {
    // BSP_LED_On(LED_GREEN);
    // // kBspButtonState = BUTTON_RELEASED;
    // // }
    // HAL_Delay(1000);
    // BSP_LED_Off(LED_GREEN);
    // HAL_Delay(1000);
  }
}
