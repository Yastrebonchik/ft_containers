cmake_minimum_required(VERSION 3.16)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

include_directories(includes)

add_executable(ft_containers srcs/main.cpp srcs/vector_tests.cpp srcs/queue_tests.cpp srcs/stack_tests.cpp srcs/list_tests.cpp srcs/map_tests.cpp)
