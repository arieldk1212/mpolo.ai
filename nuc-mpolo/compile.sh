cmake -B build \
  -DCMAKE_TOOLCHAIN_FILE=cmake/gcc-arm-none-eabi.cmake \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
