# Минимальная версия CMake, необходимая для проекта
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
# Создаем проект и указываем язык C++ (CXX)
project(task_5_2 LANGUAGES CXX)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
# Запрещаем переход к более старому стандарту, если C++17 недоступен
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем вложенный CMakeLists.txt в папке temp
add_subdirectory(temp)
# Собираем программу app из main.cpp
add_executable(app main.cpp)
# Подключаем библиотеку temp_lib к программе
target_link_libraries(app PUBLIC temp_lib)
