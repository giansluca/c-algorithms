# unity building
add_library(unity-framework STATIC unity/unity.c)
set(UNITY_HEADER_FILES
    unity/unity.h
    unity_internal.h)
set_target_properties(unity-framework PROPERTIES PUBLIC_HEADER "${UNITY_HEADER_FILES}")

add_executable(sorting_test)
target_sources(sorting_test PRIVATE modules/sorting_test.c)
target_link_libraries(sorting_test PRIVATE algorithms unity-framework)

add_executable(various_test)
target_sources(various_test PRIVATE modules/various_test.c)
target_link_libraries(various_test PRIVATE algorithms unity-framework)