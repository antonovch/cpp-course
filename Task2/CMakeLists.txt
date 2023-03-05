cmake_minimum_required(VERSION 3.15)
project(serializer)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE Debug)

add_library(serializer serializer.cpp)
add_executable(task2 main.cpp)
target_link_libraries(task2 serializer)
