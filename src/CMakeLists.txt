cmake_minimum_required(VERSION 3.28)
project(HeimdallSBOM LANGUAGES C CXX)

# --- Compiler settings ---
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Optional: enable warnings
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# --- Use lld if available ---
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
endif()

# --- Include directories ---
include_directories(${CMAKE_SOURCE_DIR}/include)

# --- Find packages ---
find_package(OpenSSL REQUIRED)

# --- Collect source files ---
file(GLOB_RECURSE LLD_SOURCES ${CMAKE_SOURCE_DIR}/src/lld/*.cpp)
file(GLOB_RECURSE GOLD_SOURCES ${CMAKE_SOURCE_DIR}/src/gold/*.cpp)
set(SOURCES
    ${LLD_SOURCES}
    ${GOLD_SOURCES}
)

# --- Create executable ---
add_executable(heimdall ${SOURCES})

# --- Set target properties ---
set_target_properties(heimdall PROPERTIES
    OUTPUT_NAME "heimdall"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# --- Link libraries ---
target_link_libraries(heimdall PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Optional: print info
message(STATUS "Using C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Using linker flags: ${CMAKE_EXE_LINKER_FLAGS}")
message(STATUS "Sources collected: ${SOURCES}")
