cmake_minimum_required(VERSION 3.15)

project(linked_list)

add_library(nv_linked_list SHARED src/linked_list.c)
target_include_directories(nv_linked_list PUBLIC include)

add_executable(test_list tests/test_list.c)
target_link_libraries(test_list nv_linked_list)

add_test(test_linked_list test_list)