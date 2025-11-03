# Minimum required CMake version and project setup
cmake_minimum_required(VERSION 3.31)
project(heimdall VERSION 1.0 LANGUAGES C CXX)

# Set default C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Optionally set compiler if needed (GCC 13 example)
# set(CMAKE_C_COMPILER gcc-13)
# set(CMAKE_CXX_COMPILER g++-13)

# Automatically collect all .cpp source files in src/
file(GLOB_RECURSE HEIMDALL_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Create the executable
add_executable(heimdall ${HEIMDALL_SOURCES})

# Include directories
target_include_directories(heimdall
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link libraries (adjust if you need more)
find_package(Threads REQUIRED)
target_link_libraries(heimdall PRIVATE Threads::Threads)

# Set target properties
set_target_properties(heimdall PROPERTIES
    OUTPUT_NAME "heimdall"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Optional: compiler flags for better warnings and optimizations
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(heimdall PRIVATE -Wall -Wextra -O2 -march=native)
endif()
