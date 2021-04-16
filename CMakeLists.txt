cmake_minimum_required(VERSION 3.5)

if (NOT DEFINED PROJECT_NAME)
	add_definitions(-LV_LVGL_H_INCLUDE_SIMPLE)
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(lvgl-demo)
else()
    message(FATAL_ERROR "LV PORT ESP32: This must be a project's main CMakeLists.txt.")
endif()
