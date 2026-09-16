cmake_minimum_required(VERSION 3.20)
project(MathTest)

set(CMAKE_CXX_STANDARD 20)

# Статическая библиотека Lib
add_library(Lib STATIC
        Lib/task.cpp
        Lib/task.h
        Lib/task.h
        Lib/task.h
        Lib/task.cpp
)

# Основное приложение
add_executable(MathTest
        MathTest/main.cpp
        MathTest/main.cpp
)

target_link_libraries(MathTest PRIVATE Lib)


# GoogleTest
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Тесты
add_executable(MathTests
        Tests/tests.cpp
        Tests/tests.cpp
)

target_link_libraries(
        MathTests
        PRIVATE
        Lib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(MathTests)