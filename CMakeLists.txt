cmake_minimum_required(VERSION 3.10)
project(get_next_line C)

set(CMAKE_C_STANDARD 99)

add_executable(get_next_line get_next_line.c get_next_line_utils.c
        get_next_line_test.c)