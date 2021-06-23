add_library(shell_sort src/shell_sort.c)
target_include_directories(shell_sort PUBLIC include)
target_link_libraries(shell_sort common_sort_def)
target_compile_options(shell_sort PRIVATE -Wno-unused-function)

add_executable(shell_sort_test tests/test_shell_sort.c)
target_link_libraries(shell_sort_test shell_sort)
target_compile_options(shell_sort_test PRIVATE -Wno-unused-function)

add_test(test_shell_sort shell_sort_test)