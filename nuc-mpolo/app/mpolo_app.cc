#include "cmsis_os2.h"
#include "mpolo_app.h"

#include <cstdio>

#include "uart/mpolo_uart.h"

__IO uint32_t kBspButtonState = BUTTON_RELEASED;

extern "C" void MpoloDefaultTask(void* arguments) {
  std::printf("Mpolo.ai App Starting..\r\n");

  mpolo::uart::UartTxPacket demo_packet;
  demo_packet.kMessage = "HI!\r\n";

  while (true) {
    mpolo::uart::MpoloUart::Transmit(demo_packet);
    osDelay(500);
  }

  // if (kBspButtonState == BUTTON_PRESSED) {
  // BSP_LED_On(LED_GREEN);
  // // kBspButtonState = BUTTON_RELEASED;
  // // }
  // HAL_Delay(1000);
  // BSP_LED_Off(LED_GREEN);
  // HAL_Delay(1000);

  osThreadTerminate(NULL);
}
