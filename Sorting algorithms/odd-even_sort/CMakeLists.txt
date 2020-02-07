cmake_minimum_required(VERSION 3.15)

project(odd-even_sort)

add_library(nv_odd-even_sort src/odd-even_sort.c)
target_include_directories(nv_odd-even_sort PUBLIC include)
target_link_libraries(nv_odd-even_sort PUBLIC nv_bubble_sort)

add_executable(odd-even_sort_test tests/test_odd-even_sort.c)
target_link_libraries(odd-even_sort_test nv_odd-even_sort)

add_test(test_odd-even_sort odd-even_sort_test)