add_library(assortsed INTERFACE)
target_sources(assortsed INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/assortsed.h)
target_include_directories(assortsed INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(assortsed 
    INTERFACE
        ya_bubble_sort 
        ya_quick_sort
        ya_selection_sort
        ya_insertion_sort
        ya_shaker_sort
        ya_comb_sort
        ya_oddeven_sort
        ya_shell_sort
        ya_merge_sort
)