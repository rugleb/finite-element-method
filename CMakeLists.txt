cmake_minimum_required(VERSION 3.9)
project(fem)

set(CMAKE_CXX_STANDARD 11)

add_library(Matrix libs/matrix.cpp)

add_library(Element src/Element.cpp)
add_library(Solution src/Solution.cpp)

add_executable(fem main.cpp)

target_link_libraries(fem Solution Element Matrix)
