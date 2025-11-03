# Minimum CMake version
cmake_minimum_required(VERSION 3.31)

# Project declaration
project(heimdall VERSION 1.0 LANGUAGES C CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Optionally set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Find packages
find_package(OpenSSL REQUIRED)

# Collect source files automatically
file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*.c
)

file(GLOB_RECURSE HEADERS
    include/*.h
    include/*.hpp
)

# Create executable target
add_executable(heimdall ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(heimdall PRIVATE include)

# Link libraries
target_link_libraries(heimdall PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Set target properties properly
set_target_properties(heimdall PROPERTIES
    OUTPUT_NAME "heimdall"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Enable compiler warnings
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(heimdall PRIVATE -Wall -Wextra -Wpedantic)
endif()
