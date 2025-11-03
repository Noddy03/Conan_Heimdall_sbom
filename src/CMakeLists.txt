# Minimum CMake version
cmake_minimum_required(VERSION 3.20)

# Project name and version
project(Heimdall VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable warnings
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Optionally enable Release by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Option to enable GCC plugin
option(ENABLE_GCC_PLUGIN "Build Heimdall with GCC plugin support" OFF)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Base source files
set(SOURCES
    src/main.cpp
    lld/LLDAdapter.cpp
    gold/GoldAdapter.cpp
    # Add other source files here
)

# Conditionally include GCC plugin files
if(ENABLE_GCC_PLUGIN)
    message(STATUS "GCC plugin support enabled")
    list(APPEND SOURCES
        gcc_plugin/MyGccPlugin.cpp
        # Add other plugin source files here
    )
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gcc_plugin/include)
endif()

# Add executable
add_executable(heimdall ${SOURCES})

# Link libraries if needed
# target_link_libraries(heimdall PRIVATE <library>)

# Installation rules
install(TARGETS heimdall DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
