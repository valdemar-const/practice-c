cmake_minimum_required(VERSION 3.15)

project(shaker_sort)

add_library(nv_shaker_sort src/shaker_sort.c)
target_include_directories(nv_shaker_sort PUBLIC include)

add_executable(nv_shaker_sort_test tests/test_shaker_sort.c)
target_link_libraries(nv_shaker_sort_test nv_shaker_sort)

add_test(test_shaker_sort nv_shaker_sort_test)