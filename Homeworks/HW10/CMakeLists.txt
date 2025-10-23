
add_executable(HW10 hw10_main.c t10_6e.c t15.c)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR = " ${CMAKE_CURRENT_SOURCE_DIR})

# Підключаємо поточну папку як include-директорію для .h файлів
target_include_directories(HW10 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})