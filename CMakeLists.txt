cmake_minimum_required(VERSION 3.14)
project(ArrayList C)

set(CMAKE_C_STANDARD 99)

add_executable(ArrayList main.c ArrayList.h ArrayListImpl.c)