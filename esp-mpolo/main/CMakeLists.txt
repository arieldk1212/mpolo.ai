idf_component_register(
  SRCS
 "main.cc"

  INCLUDE_DIRS 
  "."
  "util"
  "core"
  "sensors"
  "uart"

  REQUIRES
  # esp-dsp # Not needed
)