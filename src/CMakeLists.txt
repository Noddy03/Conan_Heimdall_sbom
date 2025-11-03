cmake_minimum_required(VERSION 3.20)
project(Heimdall VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

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

# Add executable
add_executable(heimdall ${SOURCES})

# Include directories
target_include_directories(heimdall PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
if(ENABLE_GCC_PLUGIN)
    target_include_directories(heimdall PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/gcc_plugin/include)
endif()

# Optional: set target properties
set_target_properties(heimdall PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# Installation rules
install(TARGETS heimdall DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
