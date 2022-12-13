cmake_minimum_required(VERSION 3.15)
project(PrivateServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(PrivateServer main.cpp connection.cpp connection.h FileMenadzer.cpp FileMenadzer.h)
