cmake_minimum_required(VERSION 3.22)
project(query_text)

set(CMAKE_CXX_STANDARD 17)

add_executable(query_text main.cpp TextQuery.h TextQuery.cpp)
