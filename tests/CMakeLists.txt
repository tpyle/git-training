include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(mathlib_tests
    test_arithmetic.cpp
    test_stats.cpp
    test_number_theory.cpp
)
target_link_libraries(mathlib_tests PRIVATE mathlib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(mathlib_tests)
