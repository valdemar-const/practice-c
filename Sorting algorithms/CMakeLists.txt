project(sorts_collection LANGUAGES C)

add_subdirectory(common)

add_subdirectory(bubble_sort)
add_subdirectory(quick_sort)
add_subdirectory(selection_sort)
add_subdirectory(insertion_sort)
add_subdirectory(shaker_sort)
add_subdirectory(comb_sort)
add_subdirectory(odd-even_sort)
add_subdirectory(shell_sort)
add_subdirectory(merge_sort)

add_library(sortscol INTERFACE)
target_sources(sortscol INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/sortscol.h)
target_include_directories(sortscol INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(sortscol 
    INTERFACE
        nv_bubble_sort 
        nv_quick_sort
        nv_selection_sort
        nv_insertion_sort
        nv_shaker_sort
        nv_comb_sort
        nv_odd-even_sort
        nv_shell_sort
        nv_merge_sort
)