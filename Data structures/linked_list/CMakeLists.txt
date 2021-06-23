cmake_minimum_required(VERSION 3.15)

project(linked_list)

add_library(ya_linked_list src/linked_list.c)
target_include_directories(ya_linked_list PUBLIC include)

add_executable(test_list tests/test_list.c)
target_link_libraries(test_list ya_linked_list)

add_test(test_linked_list test_list)