cmake_minimum_required(VERSION 3.15)

project(
    YAAL
    VERSION 0.11
    DESCRIPTION "Yet another algorithm library"
    HOMEPAGE_URL "https://github.com/valdemar-const/practice-c"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Werror -pedantic)

enable_testing()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory(Data\ structures/linked_list)
add_subdirectory(Data\ structures/binary_tree)

add_subdirectory(Sorting\ algorithms)