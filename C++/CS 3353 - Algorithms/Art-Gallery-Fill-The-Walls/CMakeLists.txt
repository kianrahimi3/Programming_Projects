cmake_minimum_required(VERSION 3.16)
project(21f_pa01_kian_s_team)
#set (EXE_NAME 21F-PA01)

set(CMAKE_CXX_STANDARD 14)

set (input01 "input/testing.txt")

# Copy data files to build dir
foreach(file IN LISTS input01)
    configure_file(${file} ${file} COPYONLY)
endforeach()

include_directories(src)

add_executable(21f_pa01_kian_s_team
        src/BruteForce.cpp
        src/BruteForce.h
        src/ByShortest.cpp
        src/ByShortest.h
        src/main.cpp
        src/MostExpensive.cpp
        src/MostExpensive.h
        src/UniversalFunctions.cpp
        src/UniversalFunctions.h)
