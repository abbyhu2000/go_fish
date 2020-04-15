cmake_minimum_required(VERSION 3.15)
project(Go_Fish)

set(CMAKE_CXX_STANDARD 11)

add_executable(Go_Fish go_fish.cpp card.cpp card.h deck.cpp deck.h player.cpp player.h)