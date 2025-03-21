cmake_minimum_required(VERSION 3.20)

project(tasks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
    observer.cpp
    log_command.cpp
    mess_chain_resp.cpp
)

set (HEADERS
    observer.h
    log_command.h
    mess_chain_resp.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
