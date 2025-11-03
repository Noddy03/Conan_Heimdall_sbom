# Minimum CMake version
cmake_minimum_required(VERSION 3.31)

# Project definition
project(heimdall
    VERSION 1.0
    LANGUAGES C CXX
)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Allow verbose build output (optional)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Add required packages
find_package(OpenSSL REQUIRED)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OPENSSL_INCLUDE_DIR}
)

# Source files
file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Create executable
add_executable(heimdall ${SOURCES})

# Link libraries
target_link_libraries(heimdall PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Set target properties
set_target_properties(heimdall PROPERTIES
    OUTPUT_NAME "heimdall"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Optional: install rules
install(TARGETS heimdall
    RUNTIME DESTINATION bin
)
