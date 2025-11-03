# Top of CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

# Define the project
project(HeimdallSBOM
    VERSION 1.0
    LANGUAGES C CXX
)

# Example compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find dependencies
find_package(OpenSSL REQUIRED)
find_package(PkgConfig REQUIRED)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OPENSSL_INCLUDE_DIR}
)

# Add source files
set(SOURCES
    src/main.cpp
    src/other_module.cpp
)

# Add executable target
add_executable(heimdall ${SOURCES})

# Corrected set_target_properties usage
set_target_properties(heimdall PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE ON
)

# Link libraries
target_link_libraries(heimdall PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Optional: install rules
install(TARGETS heimdall
    RUNTIME DESTINATION bin
)
