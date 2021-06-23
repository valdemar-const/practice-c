add_library(merge_sort src/merge_sort.c)
target_include_directories(merge_sort PUBLIC include)
target_link_libraries(merge_sort common_sort_def)
target_compile_options(merge_sort PRIVATE -Wno-unused-function)

add_executable(merge_sort_test tests/test_merge_sort.c)
target_link_libraries(merge_sort_test merge_sort)
target_compile_options(merge_sort_test PRIVATE -Wno-unused-function)

add_test(test_merge_sort merge_sort_test)