#include "esp_log.h"
#include "metal.h"

#include "core/core.h"

// NOLINTBEGIN
extern "C" void app_main(void) {
  ESP_LOGI("MAIN", "eso-mpolo");

  ESP_LOGI("MAIN", "Running System Checks..");
  rt::core::ValidateCpuFrequency();
  rt::core::ValidateXtalFrequency();

  ESP_LOGI("MAIN", "Outputting Stack & Heap Consumption..");
  rt::core::RemainingStackMemory();
  rt::core::RemainingHeapkMemory();

  ESP_LOGI("MAIN", "eso-mpolo App Starting");
}
// NOLINTEND
