cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(task_5_5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

add_subdirectory(temp)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

add_executable(app main.cpp)
target_link_libraries(app PUBLIC temp_lib)
