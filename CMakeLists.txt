cmake_minimum_required(VERSION 3.16)
project(GildedRoseKata LANGUAGES CXX)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

add_subdirectory(ext)
add_subdirectory(src)
add_subdirectory(test)
