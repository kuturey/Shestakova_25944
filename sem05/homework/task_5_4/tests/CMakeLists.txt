# Подключаем встроенный модуль для внешних зависимостей
include(FetchContent)

# Указываем, откуда получить исходники GoogleTest версии 1.15.2
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

# Согласуем настройки CRT для GoogleTest при сборке MSVC в Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# Скачиваем (при необходимости) и подключаем GoogleTest к проекту
FetchContent_MakeAvailable(googletest)

# Включаем регистрацию тестов для CTest в текущем каталоге сборки
# Для запуска CTest из корня обычно включают тестирование в корневом CMakeLists.txt
enable_testing()

# Собираем программу с корректными проверками
add_executable(tests_success tests.cpp)
# Подключаем GoogleTest с готовой main() и проверяемую библиотеку
target_link_libraries(tests_success PUBLIC GTest::gtest_main temp_lib)

# Отдельная программа с нарочно неудачными EXPECT/ASSERT
add_executable(tests_failure failure_demo.cpp)
# Также подключаем GoogleTest и нашу библиотеку
target_link_libraries(tests_failure PUBLIC GTest::gtest_main temp_lib)

# Подключаем механизм регистрации GoogleTest в CTest
include(GoogleTest)
# Регистрируем только успешные тесты; failure_demo запускается отдельно
gtest_discover_tests(tests_success)
