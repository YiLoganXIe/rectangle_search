cmake_minimum_required(VERSION 3.13)
project(rectangle_search)

set(CMAKE_CXX_STANDARD 11)
set(rectangle_search_COMPILE_OPTIONS -Wall -Werror)
add_executable(rectangle_search rectangle_search_skeleton.cc controller.h controller.cc exception.h exception.cc rectangle.h rectangle.cc)