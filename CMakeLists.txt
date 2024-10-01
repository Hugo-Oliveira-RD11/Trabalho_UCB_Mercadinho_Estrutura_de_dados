cmake_minimum_required(VERSION 3.29)
project(Trabalho_ED C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Trabalho_ED  procedure.h procedure.c tela.h tela.c
                           main.c)
