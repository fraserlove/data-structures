cmake_minimum_required(VERSION 3.10)
project(structures)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)
FetchContent_MakeAvailable(googletest)

add_library(structures INTERFACE)
target_include_directories(structures INTERFACE include)

enable_testing()

include(GoogleTest)

file(GLOB TEST_SOURCES tests/*.cpp)
foreach(test_file ${TEST_SOURCES})
    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name} ${test_file})
    target_link_libraries(${test_name} PRIVATE structures GTest::gtest_main)
    gtest_discover_tests(${test_name})
endforeach()