cmake_minimum_required(VERSION 3.12)
project(Pairwise-Sequence-Alignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pairwise-Sequence-Alignment Main.cpp globalAlignment.cpp globalAlignment.h localAlignment.cpp localAlignment.h)