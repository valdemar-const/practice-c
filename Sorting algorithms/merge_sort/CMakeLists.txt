cmake_minimum_required(VERSION 3.15)

project(merge_sort)

add_library(nv_merge_sort src/merge_sort.c)
target_include_directories(nv_merge_sort PUBLIC include)

add_executable(nv_merge_sort_test tests/test_merge_sort.c)
target_link_libraries(nv_merge_sort_test nv_merge_sort)

add_test(test_merge_sort nv_merge_sort_test)