cmake_minimum_required(VERSION 3.15)

project(shell_sort)

add_library(nv_shell_sort src/shell_sort.c)
target_include_directories(nv_shell_sort PUBLIC include)
target_link_libraries(nv_shell_sort common_sort_def)

add_executable(nv_shell_sort_test tests/test_shell_sort.c)
target_link_libraries(nv_shell_sort_test nv_shell_sort)

add_test(test_shell_sort nv_shell_sort_test)