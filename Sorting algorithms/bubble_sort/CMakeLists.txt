add_library(bubble_sort src/bubble_sort.c)
target_include_directories(bubble_sort PUBLIC include)
target_link_libraries(bubble_sort common_sort_def)
target_compile_options(bubble_sort PRIVATE -Wno-unused-function)

add_executable(bubble_sort_test tests/test_bubble_sort.c)
target_link_libraries(bubble_sort_test bubble_sort)
target_compile_options(bubble_sort_test PRIVATE -Wno-unused-function)

add_test(test_bubble_sort bubble_sort_test)