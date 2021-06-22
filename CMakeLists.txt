cmake_minimum_required(VERSION 3.16)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)

add_executable(ft_containers main.cpp list.hpp vector.hpp map.hpp algorithm.hpp vector_tests.cpp vector_tests.hpp queue.hpp queue_tests.cpp queue_tests.hpp test_headers.hpp stack.hpp stack_tests.cpp stack_tests.hpp list_tests.cpp list_tests.hpp map_tests.cpp map_tests.hpp)
