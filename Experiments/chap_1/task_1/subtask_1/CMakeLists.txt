cmake_minimum_required(VERSION 3.10)
project(equalizeHist)

find_package(OpenCV REQUIRED)

add_executable(subtask_1 subtask_1.cpp equalizeHist.cpp)

target_link_libraries(subtask_1 ${OpenCV_LIBS})