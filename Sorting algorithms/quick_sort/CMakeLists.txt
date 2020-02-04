cmake_minimum_required(VERSION 3.15)

project(quick_sort)

add_library(nv_quick_sort src/quick_sort.c)
target_include_directories(nv_quick_sort PUBLIC include)

add_executable(nv_quick_sort_test tests/test_quick_sort.c)
target_link_libraries(nv_quick_sort_test nv_quick_sort)

add_test(test_quick_sort nv_quick_sort_test)