cmake_minimum_required(VERSION 3.16)
project(ft_containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ft_containers main.cpp list.hpp vector.hpp map.hpp list.cpp tests.hpp algorithm.hpp vector.cpp vector_tests.cpp vector_tests.hpp queue.hpp queue_tests.cpp queue_tests.hpp test_headers.hpp)
