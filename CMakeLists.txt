cmake_minimum_required(VERSION 3.15)

project(c-practice VERSION 0.0.1 LANGUAGES C)
set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra -std=c11 -pedantic)

enable_testing()

add_subdirectory(Data\ structures/linked_list)
add_subdirectory(Data\ structures/binary_tree)