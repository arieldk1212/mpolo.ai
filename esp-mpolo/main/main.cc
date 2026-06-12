#include "esp_log.h"

#include "core/core.h"

extern "C" void app_main(void) {
  ESP_LOGI("MAIN", "Main Running..");

  rt::core::CheckCpu();
  rt::core::CheckXtal();
}
