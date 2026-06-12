#ifndef CORE_H_
#define CORE_H_

#include "esp_clk_tree.h"
#include "esp_log.h"

#include "soc/rtc.h"

namespace rt::core {

// Return the frequency of the Crystal
static void CheckXtal() {
  rtc_xtal_freq_t xtal_freq = rtc_clk_xtal_freq_get();
  ESP_LOGI("XTAL", "Crystal Frequency: %dMHZ", static_cast<int>(xtal_freq));
}

// Return the frequency of the CPU
static void CheckCpu() {
  uint32_t cpu_freq{0};
  esp_err_t result = esp_clk_tree_src_get_freq_hz(
      soc_module_clk_t::SOC_MOD_CLK_CPU,
      esp_clk_tree_src_freq_precision_t::ESP_CLK_TREE_SRC_FREQ_PRECISION_APPROX,
      &cpu_freq);
  if (result == ESP_OK) {
    ESP_LOGI("CPU", "CPU Frequency: %dMHZ",
             static_cast<int>(cpu_freq / 10000000));
  }
}

}  // namespace rt::core

#endif
