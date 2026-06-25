#include "mpolo_app.h"
#include "stm32g4xx_hal.h"

#include <cstdio>

#include "uart/mpolo_uart.h"

__IO uint32_t kBspButtonState = BUTTON_RELEASED;

void MpoloMain() {
  mpolo::uart::UartTxPacket packet;
  packet.kMessage = "HI!";

  while (true) {
    mpolo::uart::Transmit(packet);
    // osDelay(100);
    HAL_Delay(500);
  }
}

extern "C" void MpoloDefaultTask() {
  std::printf("Mpolo.ai App Starting..\n\r");

  MpoloMain();

  // if (kBspButtonState == BUTTON_PRESSED) {
  // BSP_LED_On(LED_GREEN);
  // // kBspButtonState = BUTTON_RELEASED;
  // // }
  // HAL_Delay(1000);
  // BSP_LED_Off(LED_GREEN);
  // HAL_Delay(1000);
}
