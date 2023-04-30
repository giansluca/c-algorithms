cmake_minimum_required(VERSION 3.25)
project(algorithms VERSION 1.0)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(SOURCE_FILES
        src/main.c
        src/sorting/bubble_sort.c
        src/sorting/selection_sort.c
        src/sorting/insertion_sort.c
        src/sorting/merge_sort.c
        src/sorting/quick_sort.c
        src/searching/binary_search.c
        src/various/string_permutations.c
        src/various/factorial.c
        src/various/fibonacci.c
        src/various/string_concat.c
        src/various/utils.c)

add_executable(c-algorithms ${SOURCE_FILES})

target_compile_options(c-algorithms PRIVATE -m64 -Wall)

target_link_options(c-algorithms PRIVATE LINKER:-lm)