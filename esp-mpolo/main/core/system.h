#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "mpolo_string.h"

#include "drivers/mpolo_uart.h"

namespace rt::core {

class System {
 public:
  struct Drivers {
    drivers::Uart uart;
  };

  struct Modules {};

  struct Leds {};

  System() = default;

 private:
  Drivers drivers_;
  std::string name_{"esp32s3"};
};

/**
 int main() {
    auto& system = System::instance(); // Singleton
    auto& uart = system.uart();

    // Configure serial interface
    uart.configBaud(115200);
    uart.setReadEnabled(true);
    uart.setWriteEnabled(true);

    // Start with asynchronous read
    auto& uartSocket = system.uartSocket();
    System::Uart::CharType ch = 0;
    readChar(uartSocket, ch);

    // Run the event loop
    device::interrupt::enable();
    auto& el = system.eventLoop();
    el.run();

    GASSERT(0); // Mustn't exit
    return 0;
 */

}  // namespace rt::core

#endif
