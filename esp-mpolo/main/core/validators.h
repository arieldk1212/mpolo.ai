#ifndef VALIDATORS_H_
#define VALIDATORS_H_

#include "metal.h"

#include <cassert>
#include <stdexcept>

namespace rt::core {

static void ValidateCpuFrequency() {
  auto freq = CheckCpu();
  freq /= kCpuFreqDivider;
  if (freq != kCpuFreq) {
    ESP_LOGE("CPU", "CPU Frequency Not as Config: %dMHZ", freq);
  }
}

static void ValidateXtalFrequency() {
  auto freq = CheckXtal();
  if (freq != kXtalFreq) {
    ESP_LOGE("XTAL", "Xtal Frequency Not as Config: %dMHZ", freq);
  }
}

}  // namespace rt::core

#endif
