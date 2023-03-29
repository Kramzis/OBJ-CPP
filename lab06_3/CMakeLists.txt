cmake_minimum_required(VERSION 3.23)
project(lab06_3)

set(CMAKE_CXX_STANDARD 23)
message(STATUS "start running cmake...")

set(BOOST_ROOT "C:/boost/boost_1_80_0")
set(BOOST_INCLUDE_DIR "C:/boost/boost_1_80_0/include")
set(BOOST_LIBRARY_DIR "C:/boost/boost_1_80_0/libs")

find_package(Boost)
include_directories(${BOOST_INCLUDE_DIR})

if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()
add_executable(lab06_3 main.cpp)
