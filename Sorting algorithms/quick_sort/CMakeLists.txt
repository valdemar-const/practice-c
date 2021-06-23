add_library(quick_sort src/quick_sort.c)
target_include_directories(quick_sort PUBLIC include)
target_link_libraries(quick_sort common_sort_def)
target_compile_options(quick_sort PRIVATE -Wno-unused-function)

add_executable(quick_sort_test tests/test_quick_sort.c)
target_link_libraries(quick_sort_test quick_sort)
target_compile_options(quick_sort_test PRIVATE -Wno-unused-function)

add_test(test_quick_sort quick_sort_test)