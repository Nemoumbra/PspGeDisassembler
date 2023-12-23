cmake_minimum_required(VERSION 3.26)
project(LibPSPGEDisasm)

set(CMAKE_CXX_STANDARD 20)

# Enable to have a look at PPSSPP's use of anonymous structs
# add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(src)
add_subdirectory(sample)
