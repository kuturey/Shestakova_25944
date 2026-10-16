
# Установим минимальную требуемую версию CMake
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# Название проекта и используемый язык
project(sem06_homework LANGUAGES CXX)

# Установим стандарт языка C++17
set(CMAKE_CXX_STANDARD 17)

# Установим обязательное соответствие стандарту
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавим статическую библиотеку с реализацией класса
add_library(text_document STATIC TextDocument.cpp)

# Укажем директорию с заголовочным файлом
target_include_directories(text_document PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Определим конечную цель - исполняемый файл
add_executable(sem06_demo main.cpp)

# Свяжем нашу библиотеку с исполняемым файлом
target_link_libraries(sem06_demo PRIVATE text_document)

# Подключим поддержку тестирования
include(CTest)

# Подключим модуль загрузки GoogleTest
include(FetchContent)

# Укажем источник GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Для Windows сохраним настройки компилятора
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Загрузим и подключим GoogleTest
FetchContent_MakeAvailable(googletest)

# Создадим исполняемый файл с тестами
add_executable(sem06_gtest test_text_document.cpp)

# Подключим к тестам библиотеку класса и GoogleTest
target_link_libraries(sem06_gtest PRIVATE
    text_document
    GTest::gtest_main
)

# Подключим модуль GoogleTest
include(GoogleTest)

# Зарегистрируем тесты для запуска через CTest
gtest_discover_tests(sem06_gtest)
