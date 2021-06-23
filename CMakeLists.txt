cmake_minimum_required(VERSION 3.15)

project(c-practice VERSION 0.0.1 LANGUAGES C)
set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra -Werror -Wno-unused-function -std=c11 -pedantic)

enable_testing()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(Data\ structures/linked_list)
add_subdirectory(Data\ structures/binary_tree)

add_subdirectory(Sorting\ algorithms)