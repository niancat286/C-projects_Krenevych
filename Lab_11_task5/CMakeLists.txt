# Створюємо виконуваний файл з вихідника main.cpp
add_executable(polynomesLab11 task11_5.c polynome.c polynome.h)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR = " ${CMAKE_CURRENT_SOURCE_DIR})

# Підключаємо поточну папку як include-директорію для .h файлів
target_include_directories(polynomesLab11 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})