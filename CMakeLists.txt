cmake_minimum_required(VERSION 3.30)
project(Correction_of_Examination_885 C)

set(CMAKE_C_STANDARD 99)

add_executable(Correction_of_Examination_885 src/main.c
        include/test2013.h
        include/test2014.h
        src/test2013.c
        src/test2014.c
)
