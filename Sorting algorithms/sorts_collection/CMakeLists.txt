add_library(assortsed INTERFACE)
target_sources(assortsed INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/assortsed.h)
target_include_directories(assortsed INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(assortsed 
    INTERFACE
        bubble_sort 
        quick_sort
        selection_sort
        insertion_sort
        shaker_sort
        comb_sort
        oddeven_sort
        shell_sort
        merge_sort
)