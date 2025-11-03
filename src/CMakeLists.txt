cmake_minimum_required(VERSION 3.28)

project(HeimdallSBOM LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/gold
    ${CMAKE_SOURCE_DIR}/lld
)

# Collect all .cpp files
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/gold/*.cpp
    ${CMAKE_SOURCE_DIR}/lld/*.cpp
)

# Create executable
add_executable(heimdall ${SOURCES})

# Example: link OpenSSL if you use it
find_package(OpenSSL REQUIRED)
target_link_libraries(heimdall PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Example: compiler options
target_compile_options(heimdall PRIVATE -Wall -Wextra -Wpedantic)
