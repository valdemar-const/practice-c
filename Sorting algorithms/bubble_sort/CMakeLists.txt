add_library(ya_bubble_sort src/bubble_sort.c)
target_include_directories(ya_bubble_sort PUBLIC include)
target_link_libraries(ya_bubble_sort common_sort_def)
target_compile_options(ya_bubble_sort PRIVATE -Wno-unused-function)

add_executable(bubble_sort_test tests/test_bubble_sort.c)
target_link_libraries(bubble_sort_test ya_bubble_sort)
target_compile_options(bubble_sort_test PRIVATE -Wno-unused-function)

add_test(test_bubble_sort bubble_sort_test)