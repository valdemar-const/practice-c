cmake_minimum_required(VERSION 3.15)

project(binary_tree)

add_library(nv_binary_tree SHARED src/binary_tree.c)
target_include_directories(nv_binary_tree PUBLIC include)

add_executable(test_tree tests/test_binary_tree.c)
target_link_libraries(test_tree nv_binary_tree)

add_test(test_binary_tree test_tree)