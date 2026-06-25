#ifndef MPOLO_UART_H_
#define MPOLO_UART_H_

#include "stm32g4xx_hal_uart.h"
#include "stm32g4xx_nucleo.h"
#include "usart.h"

#include <cstdio>
#include <cstring>

namespace mpolo::uart {

static constexpr uint32_t kTimeout{1000};

struct UartTxPacket {
  const char* kMessage;
  uint32_t timeout{kTimeout};
};

class MpoloUart {
 public:
  MpoloUart()
      : uart_handler_(&hcom_uart[COM1]) {
    std::printf("Mpolo Uart Initialized.\r\n");
  }

  static void Transmit(const UartTxPacket& packet) {
    HAL_UART_Transmit(&hcom_uart[COM1],
                      reinterpret_cast<const uint8_t*>(packet.kMessage),
                      strlen(packet.kMessage), packet.timeout);
  }

 private:
  UART_HandleTypeDef* uart_handler_;
};

}  // namespace mpolo::uart

#endif
