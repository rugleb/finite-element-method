cmake_minimum_required(VERSION 3.9)
project(fem)

set(CMAKE_CXX_STANDARD 11)

add_library(matrix src/matrix.h src/matrix.cpp)

add_library(Element src/Element.cpp)
add_library(Solution src/Solution.cpp)

add_executable(app.out main.cpp)

target_link_libraries(app.out matrix Element Solution)
