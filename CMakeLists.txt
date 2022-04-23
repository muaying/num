# 数值分析演示 软件
cmake_minimum_required(VERSION 3.20)
project(learn_num)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


SET(OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/out)
if (NOT EXISTS ${OUT_DIR})
    file(MAKE_DIRECTORY ${OUT_DIR})
endif ()
SET(EXECUTABLE_OUTPUT_PATH ${OUT_DIR})
SET(LIBRARY_OUTPUT_PATH ${OUT_DIR})




add_subdirectory(source)


