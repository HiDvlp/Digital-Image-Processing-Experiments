cmake_minimum_required(VERSION 3.10)
project(localHistEnhance)

find_package(OpenCV REQUIRED)

add_executable(task_2 task_2.cpp localHistEnhance.cpp)

target_link_libraries(task_2 ${OpenCV_LIBS})