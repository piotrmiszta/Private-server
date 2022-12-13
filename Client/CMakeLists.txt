cmake_minimum_required(VERSION 3.23)
project(PrivateClient)

set(CMAKE_CXX_STANDARD 14)

add_executable(PrivateClient main.cpp connections.cpp connections.h)
