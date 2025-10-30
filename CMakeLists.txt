cmake_minimum_required(VERSION 4.0)
project(TEST_GRAND_PRIX C)

set(CMAKE_C_STANDARD 11)

add_executable(TEST_GRAND_PRIX main.c
        pilote.c
        pilote.h
        ecurie.c
        ecurie.h
        menu.c
        menu.h
        GrandPrix.c
        GrandPrix.h
        classement.c
        classement.h)
