cmake_minimum_required(VERSION 3.5)

project(RPi_Menu)

set(MULTITHREAD "pthread")
set(WIREPI "lwiringPi")

link_libraries(stdc++fs)

add_definitions(-std=c++17 -g -03)

add_subdirectory(menu)
add_subdirectory(menu_node)
add_subdirectory(oled)