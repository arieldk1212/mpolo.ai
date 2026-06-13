#ifndef MPOLO_UART_H_
#define MPOLO_UART_H_

#include "esp_log.h"
#include "metal.h"
#include "portmacro.h"

#include <functional>
#include <string>
#include <utility>

#include "core/comm.h"
#include "driver/uart.h"
#include "freertos/callback.h"
#include "util/mpolo_vector.h"

namespace rt::drivers {

static const char* const kTag = "UART";
static constexpr int kBaudRate{115200};
static constexpr int kUartStackSize{4096};
static constexpr int kUartBufferSize{1024};

struct UartConfig {
  uint8_t rx_port;
  uint8_t tx_port;
  uart_port_t uart_port;
  int baud_rate;
  int stack_size;
};

struct UartCommConfig {
  int baud_rate;
  int data_bits = UART_DATA_8_BITS;
  int parity = UART_PARITY_DISABLE;
  int stop_bits = UART_STOP_BITS_1;
  int flow_ctrl = UART_HW_FLOWCTRL_DISABLE;
  int source_clk = UART_SCLK_DEFAULT;
};

class Uart : public core::Communication {
 public:
  using Buffer = util::MpoloVector<uint8_t, kUartStackSize>;

  Uart() {
    esp_log_level_set(kTag, esp_log_level_t::ESP_LOG_INFO);
    ESP_LOGI(kTag, "Uart Resource Created");
  }
  ~Uart() { ESP_LOGI(kTag, "Uart Resource Deleted"); }

  Uart(const Uart& other) = delete;
  Uart& operator=(const Uart&) = delete;
  Uart(Uart&& other) = delete;
  Uart& operator=(Uart&& other) = delete;

  void SingleRead() {
    int length = uart_read_bytes(uart_config_.uart_port, buffer_.Get().data(),
                                 buffer_.Size(), 20 / portTICK_PERIOD_MS);
    uart_write_bytes(uart_config_.uart_port, buffer_.Get().data(),
                     buffer_.Size());
    if (length) {
      ESP_LOGI(kTag, "Recv str: %s", buffer_.Get().data());
    }
  }

  void Read() override {
    Buffer buffer;

    for (;;) {
      int length = uart_read_bytes(uart_config_.uart_port, buffer.Get().data(),
                                   buffer.Size(), 20 / portTICK_PERIOD_MS);
      uart_write_bytes(uart_config_.uart_port, buffer.Get().data(),
                       buffer.Size());
      if (length) {
        ESP_LOGI(kTag, "Recv str: %s", buffer_.Get().data());
      }
    }
  }

  void UartCallback();

  void Send() override {}

  [[nodiscard]] const UartConfig& GetConfig() const { return uart_config_; }
  [[nodiscard]] const UartCommConfig& GetCommConfig() const {
    return uart_comm_config_;
  }

 private:
  Buffer buffer_;
  UartCommConfig uart_comm_config_{.baud_rate = kBaudRate};
  UartConfig uart_config_{.rx_port = 44,
                          .tx_port = 43,
                          .uart_port = uart_port_t::UART_NUM_0,
                          .baud_rate = kBaudRate,
                          .stack_size = kUartStackSize};
};

struct UartTask {
  const char* kName;
  std::function<void()> method;
};

static void RunUartCallback(Uart* uart, UartTask& callback) {
  auto task = xTaskCreatePinnedToCore(core::TaskTrampoline, callback.kName,
                                      uart->GetConfig().stack_size,
                                      &(callback.method), 10, nullptr, 0);
}

template <typename TFunc>
static void RunUartCallback(Uart* uart, TFunc&& func,
                            const std::string& callback_name) {
  auto task =
      xTaskCreatePinnedToCore(std::forward<TFunc>(func), callback_name,
                              uart->GetConfig().stack_size, 0, 10, nullptr, 0);
}

}  // namespace rt::drivers

#endif
