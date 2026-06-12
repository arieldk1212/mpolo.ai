#ifndef MATH_OPS_H_
#define MATH_OPS_H_

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "driver/uart.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soc/gpio_struct.h"
#include "soc/uart_struct.h"
#include "util/mpolo_vector.h"

namespace rt::dsp {

static constexpr int kNSamples{1024};

struct DspData {
  util::MpoloVector<float, kNSamples> input_data;
  util::MpoloVector<float, kNSamples> window_coeff;
  util::MpoloVector<float, kNSamples * 2> y_cf;
};

}  // namespace rt::dsp

#endif
