cmake_minimum_required(VERSION 3.15)
project(PA04_amazing)
set(CMAKE_CXX_STANDARD 14)

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....
# if you need more, add them here and in the foreach stmt below.
set (input01 "input01.txt")
set (input02 "input02.txt")
set (input03 "input03.txt")
set (input04 "input04.txt")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03)
    configure_file(${file} ${file} COPYONLY)
endforeach()


# Create the executable for sorting
add_executable(PA04_amazing main.cpp DSList.cpp DSList.h DSString.cpp DSString.h DSStack.h Coordinates.h DSVector.h MazeAdjList.h tests.cpp MazeWork.cpp MazeWork.h)








