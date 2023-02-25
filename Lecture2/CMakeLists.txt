cmake_minimum_required(VERSION 3.25)
project(test_project)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug) 

add_library(funcs funcs.cpp) 
add_executable(my_program multiFileProgram.cpp)
target_link_libraries(my_program funcs)
