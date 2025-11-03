# Minimum required version of CMake
cmake_minimum_required(VERSION 3.28)

# Project name and languages
project(HeimdallSBOM LANGUAGES C CXX)

# Optional: set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories (adjust according to your project)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find packages
find_package(OpenSSL REQUIRED)

# Recursively collect all .cpp files in src/lld and src/gold
file(GLOB_RECURSE LLD_SOURCES ${CMAKE_SOURCE_DIR}/src/lld/*.cpp)
file(GLOB_RECURSE GOLD_SOURCES ${CMAKE_SOURCE_DIR}/src/gold/*.cpp)
set(SOURCES ${LLD_SOURCES} ${GOLD_SOURCES})

# Create executable target
add_executable(heimdall ${SOURCES})

# Link libraries
target_link_libraries(heimdall PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Set target properties
set_target_properties(heimdall PROPERTIES
    OUTPUT_NAME "heimdall"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Optional: compile options
target_compile_options(heimdall PRIVATE
    -Wall -Wextra -Wpedantic
)

# Optional: install rules
install(TARGETS heimdall
    RUNTIME DESTINATION bin
)
