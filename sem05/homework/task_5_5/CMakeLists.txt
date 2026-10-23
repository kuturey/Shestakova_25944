# Устанавливаем минимальную версию CMake
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# Создаем проект и указываем язык C++
project(task_5_5 LANGUAGES CXX)

# Устанавливаем стандарт языка C++17
set(CMAKE_CXX_STANDARD 17)

# Указываем, что использование стандарта C++17 обязательно
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем опцию для включения и отключения сборки тестов
# По умолчанию тесты включены (ON)
option(BUILD_TESTS "Build tests" ON)

# Подключаем папку temp с библиотекой,
# реализация которой находится только в заголовочном файле
add_subdirectory(temp)

# Если сборка тестов включена, подключаем CTest
# и добавляем папку с тестами в проект
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Создаем исполняемый файл app из main.cpp
add_executable(app main.cpp)

# Подключаем к программе библиотеку temp_lib
# PRIVATE означает, что зависимость нужна только самой программе
# Путь к temp.h передается через INTERFACE библиотеки
target_link_libraries(app PRIVATE temp_lib)
