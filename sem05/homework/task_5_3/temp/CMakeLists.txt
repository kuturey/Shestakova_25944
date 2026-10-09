add_library(temp_lib STATIC temp.cpp)
target_include_directories(temp_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
