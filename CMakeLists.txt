cmake_minimum_required(VERSION 3.7)

project(nibler)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(nibler main.cpp)
target_link_libraries(nibler ${SDL2_LIBRARIES})