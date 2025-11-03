# Minimum required CMake version
cmake_minimum_required(VERSION 3.31)

# Project definition
project(heimdall VERSION 1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Find packages
find_package(OpenSSL REQUIRED)
find_package(PkgConfig REQUIRED)

# Optional: pkg-config libraries
pkg_check_modules(JSONCPP jsoncpp REQUIRED)
pkg_check_modules(CURL libcurl REQUIRED)
pkg_check_modules(ZLIB REQUIRED)

# Include directories
include_directories(
    ${OPENSSL_INCLUDE_DIR}
    ${JSONCPP_INCLUDE_DIRS}
    ${CURL_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIRS}
)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp src/*.c)

# Define the executable
add_executable(heimdall ${SOURCES})

# Link libraries
target_link_libraries(heimdall PRIVATE
    OpenSSL::SSL
    OpenSSL::Crypto
    ${JSONCPP_LIBRARIES}
    ${CURL_LIBRARIES}
    ${ZLIB_LIBRARIES}
)

# Set target properties
set_target_properties(heimdall PROPERTIES
    OUTPUT_NAME "heimdall"
    CXX_STANDARD 14
)

# Optional: enable verbose makefile output
set(CMAKE_VERBOSE_MAKEFILE ON)

# Optional: Ninja support if needed
if(CMAKE_GENERATOR STREQUAL "Ninja")
    message(STATUS "Using Ninja build system")
endif()

# Message summary
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "OpenSSL include: ${OPENSSL_INCLUDE_DIR}")
message(STATUS "OpenSSL libraries: ${OPENSSL_LIBRARIES}")
