# Minimum CMake version and project definition
cmake_minimum_required(VERSION 3.28)
project(HeimdallSBOM LANGUAGES C CXX)

# Set C++ standard and enforce it
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Optional: Enable warnings for all compilers
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wnon-virtual-dtor -Wconversion)
endif()

# Build type default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# Source files
file(GLOB_RECURSE SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# Add executable
add_executable(heimdall ${SRC_FILES})

# Link OpenSSL
find_package(OpenSSL REQUIRED)
if(OpenSSL_FOUND)
    target_include_directories(heimdall PRIVATE ${OPENSSL_INCLUDE_DIR})
    target_link_libraries(heimdall PRIVATE OpenSSL::Crypto)
endif()

# Optional: Add libraries if needed
# target_link_libraries(heimdall PRIVATE <other-libraries>)

# Lightweight DWARF parser options
# (adjust include path if needed)
target_include_directories(heimdall PRIVATE ${PROJECT_SOURCE_DIR}/lib/LightweightDWARFParser/include)

# Compiler-specific options
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(heimdall PRIVATE -fno-exceptions -fno-rtti)
endif()

# Set target properties safely
set_target_properties(heimdall PROPERTIES
    OUTPUT_NAME "heimdall"
)

# Installation rules (optional)
install(TARGETS heimdall
    RUNTIME DESTINATION bin
)

# Enable Ninja generator if available
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "Configuration complete. C++ Standard: ${CMAKE_CXX_STANDARD}, Build type: ${CMAKE_BUILD_TYPE}")

