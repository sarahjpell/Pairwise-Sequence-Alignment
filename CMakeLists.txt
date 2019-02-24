cmake_minimum_required(VERSION 3.12)
project(Pairwise-Sequence-Alignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(localAlignment.cpp Main.cpp localAlignment.cpp localAlignment.h globalAlignment.cpp globalAlignment.h)