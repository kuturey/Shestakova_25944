include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests_success tests.cpp)
target_link_libraries(tests_success PUBLIC GTest::gtest_main temp_lib)

add_executable(tests_failure failure_demo.cpp)
target_link_libraries(tests_failure PUBLIC GTest::gtest_main temp_lib)

include(GoogleTest)
gtest_discover_tests(tests_success)
