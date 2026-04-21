cmake_minimum_required(VERSION 3.10)
project(intro_opencv)

# 找到 OpenCV
find_package(OpenCV REQUIRED)

# 包含 OpenCV 头文件
include_directories(${OpenCV_INCLUDE_DIRS})

# 生成可执行文件
add_executable(main main.cpp)

# 链接 OpenCV 库
target_link_libraries(main ${OpenCV_LIBS})