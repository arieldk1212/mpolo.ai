#ifndef MPOLO_UART_H_
#define MPOLO_UART_H_

#include "stm32g4xx_hal_uart.h"
#include "stm32g4xx_nucleo.h"
#include "usart.h"

#include <cstring>

namespace mpolo::uart {

struct UartTxPacket {
  char* kMessage;
  uint32_t timeout{COM_POLL_TIMEOUT};
};

inline void Transmit(const UartTxPacket& packet) {
  HAL_UART_Transmit(&huart1, reinterpret_cast<uint8_t*>(packet.kMessage),
                    strlen(packet.kMessage), packet.timeout);
}

}  // namespace mpolo::uart

#endif
