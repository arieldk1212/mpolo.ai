#include "esp_log.h"
#include "metal.h"

#include "core/core.h"
#include "uart/mpolo_uart.h"

// void

// NOLINTBEGIN
extern "C" void app_main(void) {
  ESP_LOGI("MAIN", "eso-mpolo");
  rt::core::CheckCpu();
  rt::core::CheckXtal();

  ESP_LOGI("MAIN", "Running System Checks..");
  rt::core::ValidateCpuFrequency();
  rt::core::ValidateXtalFrequency();

  ESP_LOGI("MAIN", "eso-mpolo starting");
}
// NOLINTEND
