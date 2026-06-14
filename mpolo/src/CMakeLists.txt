file(GLOB_RECURSE SOURCES "*.cc")
add_library(mpolo STATIC ${SOURCES})
target_include_directories(mpolo PUBLIC ${PROJECT_SOURCE_DIR}/mpolo)

add_executable(mpolo_main main.cc)
target_link_libraries(mpolo_main PUBLIC mpolo)
