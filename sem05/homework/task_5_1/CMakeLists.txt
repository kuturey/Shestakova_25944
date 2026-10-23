# Минимальная версия CMake, необходимая для проекта
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
# Создаем проект и указываем язык C++ (CXX)
project(task_5_1 LANGUAGES CXX)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
# Запрещаем переход к более старому стандарту, если C++17 недоступен
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем статическую библиотеку; temp.cpp компилируется, temp.h перечислен как файл цели
add_library(temp_lib STATIC temp.h temp.cpp)
# Собираем отдельный исполняемый файл app из main.cpp
add_executable(app main.cpp)
# Связываем app с temp_lib; PUBLIC здесь допустимо, хотя PRIVATE обычно достаточно
target_link_libraries(app PUBLIC temp_lib)
