cmake_minimum_required(VERSION 3.31)
project(heimdall VERSION 1.0 LANGUAGES C CXX)

# Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add subdirectories for your adapters
add_subdirectory(lld)
add_subdirectory(golden)

# Collect all sources
set(SOURCES
    lld/LldAdapter.cpp
    golden/GoldenAdapter.cpp
    main.cpp    # add this if you have a main program
)

# Create executable
add_executable(heimdall ${SOURCES})

# Include directories for headers
target_include_directories(heimdall
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/lld
        ${CMAKE_CURRENT_SOURCE_DIR}/golden
)

# Optional: link libraries like OpenSSL if needed
# find_package(OpenSSL REQUIRED)
# target_link_libraries(heimdall PRIVATE OpenSSL::SSL OpenSSL::Crypto)

