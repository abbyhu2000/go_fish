cmake_minimum_required(VERSION 3.15)
project(go_fish3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(go_fish3
        card.cpp
        card.h
        deck.cpp
        deck.h
        go_fish.cpp
        player.cpp
        player.h)
