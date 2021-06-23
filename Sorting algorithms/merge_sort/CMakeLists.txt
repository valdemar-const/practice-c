add_library(ya_merge_sort src/merge_sort.c)
target_include_directories(ya_merge_sort PUBLIC include)
target_link_libraries(ya_merge_sort common_sort_def)
target_compile_options(ya_merge_sort PRIVATE -Wno-unused-function)

add_executable(ya_merge_sort_test tests/test_merge_sort.c)
target_link_libraries(ya_merge_sort_test ya_merge_sort)
target_compile_options(ya_merge_sort_test PRIVATE -Wno-unused-function)

add_test(test_merge_sort ya_merge_sort_test)