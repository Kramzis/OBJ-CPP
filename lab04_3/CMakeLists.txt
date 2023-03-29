cmake_minimum_required(VERSION 3.23)
project(lab_4_zad_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_4_zad_3
        citizen.cpp
        citizen.h
        city.cpp
        city.h
        compare.cpp
        compare.h
        main.cpp
        postalcodes.cpp
        postalcodes.h)
