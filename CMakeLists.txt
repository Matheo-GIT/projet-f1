cmake_minimum_required(VERSION 4.0)
project(TEST_GRAND_PRIX C)

set(CMAKE_C_STANDARD 11)

add_executable(TEST_GRAND_PRIX main.c
        pilote.c
        pilote.h)
