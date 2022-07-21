cmake_minimum_required(VERSION 3.15)
#include(CMakePrintHelpers)

project(
        IsothermLib
        VERSION 1.0.1
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -fassociative-math -freciprocal-math -fno-signed-zeros -fno-trapping-math")


add_subdirectory(IsothermLib)
add_subdirectory(Exemplos)
add_subdirectory(Testes)

