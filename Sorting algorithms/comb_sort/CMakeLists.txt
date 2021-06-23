add_library(comb_sort src/comb_sort.c)
target_include_directories(comb_sort PUBLIC include)
target_link_libraries(comb_sort bubble_sort common_sort_def)
target_compile_options(comb_sort PRIVATE -Wno-unused-function)

add_executable(comb_sort_test tests/test_comb_sort.c)
target_link_libraries(comb_sort_test comb_sort)
target_compile_options(comb_sort_test PRIVATE -Wno-unused-function)

add_test(test_comb_sort comb_sort_test)