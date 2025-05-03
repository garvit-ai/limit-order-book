cmake_minimum_required(VERSION 3.16)
project(LimitOrderBookEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output binary
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Include headers
include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
    benchmark/*.cpp
    main.cpp
)

# Executable
add_executable(engine ${SOURCES})

# Optional: Warnings and optimization
target_compile_options(engine PRIVATE -Wall -Wextra -O3)
