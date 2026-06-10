idf_component_register(
    SRCS "rt-mpolo.cc"
    REQUIRES esp_driver_uart esp_driver_gpio
    INCLUDE_DIRS "."
)