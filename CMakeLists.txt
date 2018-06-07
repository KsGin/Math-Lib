cmake_minimum_required(VERSION 3.10)
project(MathLib)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/Cellar/gtest/include)

add_executable(MathLib main.cpp
        sources/matrix.hpp
        sources/vector.hpp
        test/matrix_test.cpp
        test/vector_test.cpp)

target_link_libraries(MathLib /usr/local/Cellar/gtest/lib/libgtest.a)