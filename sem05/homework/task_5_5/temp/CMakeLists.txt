
# Создаем библиотеку, состоящую только из заголовочного файла
# INTERFACE означает, что компилируемых .cpp файлов нет
add_library(temp_lib INTERFACE)

# Указываем директорию с заголовочным файлом temp.h
# INTERFACE передает этот путь программам и тестам,
# которые используют нашу библиотеку
target_include_directories(temp_lib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
