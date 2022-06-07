cmake_minimum_required(VERSION 3.21)
project(sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(sort main.cpp sort.h QuickSort.h ListSort.h MergeSort.h ShellSort.h TreeSort.h heapSort.h)
