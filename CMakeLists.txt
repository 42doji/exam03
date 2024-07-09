cmake_minimum_required(VERSION 3.22)
project(exam03 C)

set(CMAKE_C_STANDARD 11)

add_executable(exam03
        ft_printf/main.c
        get_next_line/get_next_line.c
        pipex/pipex.c
        ft_printf/ft_printf.c)
