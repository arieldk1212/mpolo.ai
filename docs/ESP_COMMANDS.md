# Commands for ESP32S3

1. . $IDF_PATH/esp/esp-idf/export.sh
2. idf.py create-project x
3. idf.py clang-check
4. idf.py set-target esp32s3
5. idf.py build
6. idf.py flash
7. idf.py monitor (ctrl + ])
8. idf.py build flash monitor
9. idf.py fullclean
10. idf.py menuconfig (sdkconfig)
11. idf.py -DIDF_TOOLCHAIN=clang build
12. idf.py erase-flash
