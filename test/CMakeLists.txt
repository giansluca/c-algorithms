# unity building
add_library(unity-framework STATIC unity/unity.c)
set(UNITY_HEADER_FILES
    unity/unity.h
    unity_internal.h)
set_target_properties(unity-framework PROPERTIES PUBLIC_HEADER "${UNITY_HEADER_FILES}")

add_executable(bubble_sort_test)
target_sources(bubble_sort_test PRIVATE modules/bubble_sort_test.c)
target_link_libraries(bubble_sort_test PRIVATE algorithms unity-framework)

