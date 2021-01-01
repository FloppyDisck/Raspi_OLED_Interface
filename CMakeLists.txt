cmake_minimum_required(VERSION 3.5)

project(RPi_Menu)

set(MULTITHREAD "pthread")
set(WIREPI "wiringPi")

link_libraries(stdc++fs)

add_definitions(-std=c++17 -g -O3)

# Library
add_definitions(-DUSE_WIRINGPI_LIB)
#add_definitions(-DUSE_BCM2835_LIB)

add_subdirectory(menu)
add_subdirectory(menu_node)
add_subdirectory(oled)
add_subdirectory(fonts)
