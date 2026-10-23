# Создаем статическую библиотеку temp_lib из реализации функций
add_library(temp_lib STATIC temp.cpp)
# Добавляем путь к заголовку temp.h: PUBLIC передает путь и использующим библиотеку целям
target_include_directories(temp_lib PUBLIC ${{CMAKE_CURRENT_SOURCE_DIR}})
