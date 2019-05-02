cmake_minimum_required(VERSION 3.9)
project(fem)

set(CMAKE_CXX_STANDARD 11)

add_library(Element src/Element.cpp src/Element.h)
add_library(LinearElement src/LinearElement.h)

add_executable(app.out main.cpp)

target_link_libraries(app.out Element LinearElement)
