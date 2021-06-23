add_library(ya_quick_sort src/quick_sort.c)
target_include_directories(ya_quick_sort PUBLIC include)
target_link_libraries(ya_quick_sort common_sort_def)
target_compile_options(ya_quick_sort PRIVATE -Wno-unused-function)

add_executable(ya_quick_sort_test tests/test_quick_sort.c)
target_link_libraries(ya_quick_sort_test ya_quick_sort)
target_compile_options(ya_quick_sort_test PRIVATE -Wno-unused-function)

add_test(test_quick_sort ya_quick_sort_test)