cmake_minimum_required(VERSION 3.24)
project(13.12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)

add_executable(13.03.02 13.03.02.cpp)
target_link_libraries(13.03.02 PRIVATE Boost::boost)