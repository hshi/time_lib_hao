cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(timehao)

#For find module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "~/lib/Modules")

#For definitions
add_definitions(${COMPILER_EXTRA_DEF})

#For c++ flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

message("${CMAKE_CXX_COMPILER_ID}")

include_directories(inc)

add_subdirectory(inc)

add_subdirectory(src)

add_subdirectory(test)
