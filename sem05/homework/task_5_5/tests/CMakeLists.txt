# Подключаем модуль для загрузки внешних зависимостей
include(FetchContent)

# Указываем источник и версию библиотеки GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Для Windows согласуем настройки библиотеки времени выполнения
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Загружаем и подключаем GoogleTest к проекту
FetchContent_MakeAvailable(googletest)

# Создаем исполняемый файл с успешными тестами
add_executable(tests_success tests.cpp)

# Подключаем к тестам GoogleTest и нашу библиотеку
target_link_libraries(tests_success PRIVATE
    GTest::gtest_main
    temp_lib
)

# Создаем исполняемый файл с намеренно неуспешными тестами
# Он нужен для демонстрации разницы между EXPECT и ASSERT
add_executable(tests_failure failure_demo.cpp)

# Подключаем необходимые библиотеки ко второй программе
target_link_libraries(tests_failure PRIVATE
    GTest::gtest_main
    temp_lib
)

# Подключаем модуль интеграции GoogleTest с CMake
include(GoogleTest)

# Регистрируем только успешные тесты для запуска через CTest
gtest_discover_tests(tests_success)
