set(SOURCE_FILES
        searching/binary_search.c
        sorting/bubble_sort.c
        sorting/insertion_sort.c
        sorting/merge_sort.c
        sorting/quick_sort.c
        sorting/selection_sort.c
        various/factorial.c
        various/fibonacci.c
        various/string_concat.c
        various/string_permutations.c
        various/utils.c)

set(HEADER_FILES
        searching/binary_search.h
        sorting/bubble_sort.h
        sorting/insertion_sort.h
        sorting/merge_sort.h
        sorting/quick_sort.h
        sorting/selection_sort.h
        various/factorial.h
        various/fibonacci.h
        various/string_concat.h
        various/string_permutations.h
        various/utils.h)

add_library(algorithms STATIC)
target_sources(algorithms PRIVATE ${SOURCE_FILES})
set_target_properties(algorithms PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")

add_executable(algorithms-main)
target_sources(algorithms-main PRIVATE main.c)
target_link_libraries(algorithms-main PRIVATE algorithms)

install(TARGETS algorithms algorithms-main
    RUNTIME DESTINATION ${INSTALL_CURRENT_DIR}/bin
    LIBRARY DESTINATION ${INSTALL_CURRENT_DIR}/lib
    ARCHIVE DESTINATION ${INSTALL_CURRENT_DIR}/lib
    PUBLIC_HEADER DESTINATION ${INSTALL_CURRENT_DIR}/include)   
