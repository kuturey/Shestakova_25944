# Минимальная версия CMake, необходимая для проекта
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
# Создаем проект и указываем язык C++ (CXX)
project(task_5_3 LANGUAGES CXX)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
# Запрещаем переход к более старому стандарту, если C++17 недоступен
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем папку с библиотекой temp_lib
add_subdirectory(temp)
# Всегда подключаем папку с тестами
add_subdirectory(tests)

# Создаем основную программу
add_executable(app main.cpp)
# Связываем программу с библиотекой функций
target_link_libraries(app PUBLIC temp_lib)
