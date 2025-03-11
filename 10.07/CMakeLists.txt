cmake_minimum_required(VERSION 3.24)

project(hashes VERSION 24.02.06 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

set(src hash.func.cpp)

add_library(hashes_lib STATIC ${src})

add_subdirectory(../submodules ${CMAKE_CURRENT_SOURCE_DIR}/build/submodules)


file(GLOB_RECURSE TEST_SOURCES *tests.cpp)
SET(LIBS gtest_main hashes_lib)

foreach (TEST_FILE IN LISTS TEST_SOURCES)
    get_filename_component(TEST_FILE_NAME ${TEST_FILE} NAME_WE)
    set(EXECUTABLE_NAME run_${TEST_FILE_NAME})
    add_executable(${EXECUTABLE_NAME} ${TEST_FILE})
    target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${LIBS})
    message("TEST_FILE: ${TEST_FILE}")
endforeach ()
