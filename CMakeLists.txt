cmake_minimum_required(VERSION 3.27)
project(CppGenDS)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic")

enable_testing()

add_subdirectory(0x01-ArrayStack)
add_subdirectory(tests)
