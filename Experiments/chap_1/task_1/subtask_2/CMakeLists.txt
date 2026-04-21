cmake_minimum_required(VERSION 3.10)
project(equalizeHistLocal)

find_package(OpenCV REQUIRED)

add_executable(subtask_2 subtask_2.cpp equalizeHistLocal.cpp)

target_link_libraries(subtask_2 ${OpenCV_LIBS})