cmake_minimum_required(VERSION 3.27)
project(CppGenDS)

set(CMAKE_CXX_STANDARD 23)

# Additional compile options for the Debug build
if (NOT MSVC AND CMAKE_C_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(
                -Wall
                -Wextra
                -Werror
                -Wpedantic
                -g
        )
    endif ()
endif ()

add_subdirectory(0x01-ArrayStack)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG a7f443b80b105f940225332ed3c31f2790092f47
        EXCLUDE_FROM_ALL
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(tests)
