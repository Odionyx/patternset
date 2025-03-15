cmake_minimum_required(VERSION 3.20)

project(task LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task main.cpp sql_query_builder.h sql_query_builder.cpp)
