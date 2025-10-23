# Створюємо виконуваний файл з вихідника main.cpp
add_executable(Lab10_t04 test_rational.c Rational.c)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR = " ${CMAKE_CURRENT_SOURCE_DIR})

# Підключаємо поточну папку як include-директорію для .h файлів
target_include_directories(Lab10_t04 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})