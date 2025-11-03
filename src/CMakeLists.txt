# Minimum CMake version
cmake_minimum_required(VERSION 3.20)

# Project name, version, and languages
project(Heimdall VERSION 1.0 LANGUAGES CXX)

# Set default C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Option to enable GCC plugin
option(ENABLE_GCC_PLUGIN "Build Heimdall with GCC plugin support" OFF)

# Base source files
set(SOURCES
    src/main.cpp
    lld/LLDAdapter.cpp
    gold/GoldAdapter.cpp
)

# Conditionally include GCC plugin files
if(ENABLE_GCC_PLUGIN)
    message(STATUS "GCC plugin support enabled")
    list(APPEND SOURCES
        gcc_plugin/MyGccPlugin.cpp
    )
endif()

# Create the executable
add_executable(heimdall ${SOURCES})

# Include directories
target_include_directories(heimdall
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(ENABLE_GCC_PLUGIN)
    target_include_directories(heimdall
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/gcc_plugin/include
    )
endif()

# Compiler warnings
if(MSVC)
    target_compile_options(heimdall PRIVATE /W4 /permissive-)
else()
    target_compile_options(heimdall PRIVATE -Wall -Wextra -pedantic)
endif()

# Optional: treat warnings as errors in Debug builds
# target_compile_options(heimdall PRIVATE $<$<CONFIG:Debug>:-Werror>)

# Set target properties explicitly
set_target_properties(heimdall PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Optional: link libraries if needed
# target_link_libraries(heimdall PRIVATE <library>)

# Installation rules
install(TARGETS heimdall DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
