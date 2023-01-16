cmake_minimum_required(VERSION 3.24)
project(ReballetHash)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(cryptopp-cmake)
include_directories(include)
add_executable(ReballetHash main.cpp)
target_link_libraries(ReballetHash cryptopp)