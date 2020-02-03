cmake_minimum_required(VERSION 3.15)

project(bubble_sort)

add_library(nv_bubble_sort src/bubble_sort.c)
target_include_directories(nv_bubble_sort PUBLIC include)

add_executable(bubble_sort_test tests/test_bubble_sort.c)
target_link_libraries(bubble_sort_test nv_bubble_sort)

add_test(test_bubble_sort bubble_sort_test)