#ifndef MPOLO_UART_H_
#define MPOLO_UART_H_

#include "stm32g4xx_hal_uart.h"
#include "usart.h"

#include <cstring>

namespace mpolo::uart {

struct UartTxPacket {
  const char* kMessage;
  uint32_t timeout{1000};
};

inline void Transmit(const UartTxPacket& packet) {
  HAL_UART_Transmit(&hcom_uart[COM1],
                    reinterpret_cast<const uint8_t*>(packet.kMessage),
                    strlen(packet.kMessage), packet.timeout);
}

}  // namespace mpolo::uart

#endif
