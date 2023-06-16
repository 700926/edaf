cmake_minimum_required(VERSION 3.24)
project(listas)

set(CMAKE_CXX_STANDARD 11)

add_executable(listas main.cpp CDLL.h LLL.h NODES.h CLL.h STACK.cpp STACK.h)
