cmake_minimum_required(VERSION 3.15)

project(comb_sort)

add_library(nv_comb_sort src/comb_sort.c)
target_include_directories(nv_comb_sort PUBLIC include)

add_executable(comb_sort_test tests/test_comb_sort.c)
target_link_libraries(comb_sort_test nv_comb_sort)

add_test(test_comb_sort comb_sort_test)