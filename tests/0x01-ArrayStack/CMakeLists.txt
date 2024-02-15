project(CppGenDS CXX)

add_executable(ArrayStackTests test_ArrayStack.cpp)
add_executable(ArrayTests test_Array.cpp)


target_link_libraries(ArrayStackTests gtest gtest_main)
target_link_libraries(ArrayTests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(ArrayTests)
gtest_discover_tests(ArrayStackTests)
