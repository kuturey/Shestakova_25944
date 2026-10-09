cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(task_5_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(temp_lib STATIC temp.h temp.cpp)
add_executable(app main.cpp)
target_link_libraries(app PUBLIC temp_lib)
