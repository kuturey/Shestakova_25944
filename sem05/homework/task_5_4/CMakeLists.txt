# Минимальная версия CMake, необходимая для проекта
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
# Создаем проект и указываем язык C++ (CXX)
project(task_5_4 LANGUAGES CXX)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
# Запрещаем переход к более старому стандарту, если C++17 недоступен
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Разрешаем включать и выключать сборку тестов; по умолчанию они включены
option(BUILD_TESTS "Build tests" ON)

# Подключаем папку с библиотекой temp_lib
add_subdirectory(temp)
# Подключаем тесты только при BUILD_TESTS=ON
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

# Создаем основную программу
add_executable(app main.cpp)
# Связываем программу с библиотекой функций
target_link_libraries(app PUBLIC temp_lib)
