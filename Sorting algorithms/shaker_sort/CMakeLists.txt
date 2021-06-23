add_library(shaker_sort src/shaker_sort.c)
target_include_directories(shaker_sort PUBLIC include)
target_link_libraries(shaker_sort common_sort_def)
target_compile_options(shaker_sort PRIVATE -Wno-unused-function)

add_executable(shaker_sort_test tests/test_shaker_sort.c)
target_link_libraries(shaker_sort_test shaker_sort)
target_compile_options(shaker_sort_test PRIVATE -Wno-unused-function)

add_test(test_shaker_sort shaker_sort_test)