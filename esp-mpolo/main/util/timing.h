#ifndef TIME_H_
#define TIME_H_

#include <string>

#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"

namespace rt::util {

static std::string GetTime() {
  auto current_ticks = xTaskGetTickCount();
  uint32_t time_ms = (current_ticks * 1000) / configTICK_RATE_HZ;
  return std::to_string(time_ms);
}

}  // namespace rt::util

#endif
