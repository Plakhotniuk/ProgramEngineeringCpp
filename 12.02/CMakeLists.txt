cmake_minimum_required(VERSION 3.24)
project(strings LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Google Benchmark package (REQUIRED ensures it fails if not found)
find_package(benchmark REQUIRED)

# Optional: If you're using Boost, make sure it's found
find_package(Boost REQUIRED)  # Only include if you actually need Boost

add_executable(creation.time.bench creation.time.bench.cpp)

# Enable warnings and disable optimizations for accurate benchmarking
target_compile_options(creation.time.bench PRIVATE
    -Wall -Wextra -pedantic -O0
)

# Link against Google Benchmark (& Boost if needed)
target_link_libraries(creation.time.bench PRIVATE
    benchmark::benchmark
    ${Boost_LIBRARIES}  # Only include if Boost is actually used
)