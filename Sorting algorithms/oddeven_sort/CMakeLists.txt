add_library(oddeven_sort src/oddeven_sort.c)
target_include_directories(oddeven_sort PUBLIC include)
target_link_libraries(oddeven_sort common_sort_def)
target_compile_options(oddeven_sort PRIVATE -Wno-unused-function)

add_executable(oddeven_sort_test tests/test_oddeven_sort.c)
target_link_libraries(oddeven_sort_test oddeven_sort)
target_compile_options(oddeven_sort_test PRIVATE -Wno-unused-function)

add_test(test_oddeven_sort oddeven_sort_test)