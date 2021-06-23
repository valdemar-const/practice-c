add_library(ya_shell_sort src/shell_sort.c)
target_include_directories(ya_shell_sort PUBLIC include)
target_link_libraries(ya_shell_sort common_sort_def)
target_compile_options(ya_shell_sort PRIVATE -Wno-unused-function)

add_executable(ya_shell_sort_test tests/test_shell_sort.c)
target_link_libraries(ya_shell_sort_test ya_shell_sort)
target_compile_options(ya_shell_sort_test PRIVATE -Wno-unused-function)

add_test(test_shell_sort ya_shell_sort_test)