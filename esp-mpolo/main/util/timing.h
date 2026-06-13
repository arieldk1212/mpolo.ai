#ifndef TIME_H_
#define TIME_H_

#include "freertos/FreeRTOS.h"

namespace rt::util {

static constexpr uint8_t kTimeStringBufferSize{12};

static uint32_t GetTime() {
  auto current_ticks = xTaskGetTickCount();
  uint32_t time_ms = (current_ticks * 1000) / configTICK_RATE_HZ;
  return time_ms;
}

}  // namespace rt::util

#endif
