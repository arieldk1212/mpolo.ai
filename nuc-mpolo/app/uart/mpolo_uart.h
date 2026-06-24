#ifndef MPOLO_UART_H_
#define MPOLO_UART_H_

#include "stm32g4xx_hal_uart.h"
#include "usart.h"

#include <string>

namespace mpolo::uart {

struct UartTxPacket {
  std::string message;
  uint32_t timeout{100};
};

static void Transmit() {
  UartTxPacket packet;
  packet.message = "hi";

  HAL_UART_Transmit(&huart1, packet.message.c_str(),
                    static_cast<uint16_t>(packet.message.size()), packet.timeout);
}

}  // namespace mpolo::uart

#endif
