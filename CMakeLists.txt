cmake_minimum_required(VERSION 3.5)

project(RPi_Menu)

set(MULTITHREAD "pthread")

include(FindPkgConfig)
pkg_search_module(WOLED REQUIRED woled)
include_directories(${WOLED_INCLUDE_DIRS})
link_directories(${WOLED_LIBRARY_DIRS})


link_libraries(stdc++fs)

add_definitions(-std=c++17 -g -O3)

# Library
add_definitions(-DUSE_WIRINGPI_LIB)
#add_definitions(-DUSE_BCM2835_LIB)

add_subdirectory(menu)
add_subdirectory(node)
add_subdirectory(state_node)
