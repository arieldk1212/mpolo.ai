idf_component_register(
  SRCS
 "main.cc"

  INCLUDE_DIRS 
  "."
  "util"
  "core"
  "sensors"
  "drivers"

  REQUIRES
  # esp-dsp # Not needed
  esp_driver_uart
  esp_driver_gpio
)