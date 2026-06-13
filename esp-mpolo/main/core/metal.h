#ifndef FREQUENCIES_H_
#define FREQUENCIES_H_

#include "esp_clk_tree.h"
#include "esp_log.h"

#include <functional>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soc/rtc.h"

namespace rt::core {

static constexpr uint8_t kCpuFreq{16};
static constexpr uint8_t kXtalFreq{40};
static constexpr uint32_t kCpuFreqDivider{10000000};

// Return the frequency of the Crystal
static uint8_t CheckXtal() {
  rtc_xtal_freq_t xtal_freq = rtc_clk_xtal_freq_get();
  auto xtal_freq_u8 = static_cast<uint8_t>(xtal_freq);
  ESP_LOGI("XTAL", "Crystal Frequency: %dMHZ", xtal_freq_u8);
  return xtal_freq_u8;
}

// Return the frequency of the CPU
static uint32_t CheckCpu() {
  uint32_t cpu_freq{0};
  esp_err_t result = esp_clk_tree_src_get_freq_hz(
      soc_module_clk_t::SOC_MOD_CLK_CPU,
      esp_clk_tree_src_freq_precision_t::ESP_CLK_TREE_SRC_FREQ_PRECISION_APPROX,
      &cpu_freq);
  if (result == ESP_OK) {
    ESP_LOGI("CPU", "CPU Frequency: %dMHZ",
             static_cast<int>(cpu_freq / kCpuFreqDivider));
  }
  return cpu_freq;
}

static void TaskTrampoline(void* pvParameters) {
  auto* func = static_cast<std::function<void()>*>(pvParameters);
  if ((func != nullptr) && *func) {
    (*func)();
  }
  vTaskDelete(nullptr);
}

static void RemainingStackMemory() {
  auto rem = uxTaskGetStackHighWaterMark(nullptr);
  ESP_LOGI("STACK", "Remaining Stack Memory: %d", static_cast<int>(rem));
}

static void RemainingTaskStackMemory(TaskHandle_t* handler) {
  auto rem = uxTaskGetStackHighWaterMark(*handler);
  ESP_LOGI("STACK", "Remaining Task Stack Memory: %d", static_cast<int>(rem));
}

static void RemainingHeapkMemory() {
  auto rem = esp_get_free_heap_size();
  ESP_LOGI("HEAP", "Remaining Heap Memory: %zu", rem);
}

static void RemainingMinimumHeapkMemory() {
  auto rem = esp_get_minimum_free_heap_size();
  ESP_LOGI("HEAP", "Remaining Minimum Heap Memory: %zu", rem);
}

}  // namespace rt::core

#endif
