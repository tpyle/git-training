cmake_minimum_required(VERSION 3.14)
project(mathlib VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(MATHLIB_BUILD_TESTS "Build unit tests" ON)

add_library(mathlib src/mathlib.cpp)
target_include_directories(mathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(mathlib PRIVATE -Wall -Wextra)

if(MATHLIB_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
