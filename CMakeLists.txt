cmake_minimum_required(VERSION 3.20)

project(Numerics LANGUAGES CXX)

# -----------------------------
# C++ standard
# -----------------------------
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -----------------------------
# Include directory
# -----------------------------
include_directories(${PROJECT_SOURCE_DIR}/include)

# -----------------------------
# Library source files
# -----------------------------
file(GLOB_RECURSE NUMERICS_SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_library(numerics STATIC ${NUMERICS_SOURCES})

target_include_directories(numerics
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# -----------------------------
# Main executable (demo)
# -----------------------------
add_executable(demo
    ${PROJECT_SOURCE_DIR}/app/main.cpp)

target_link_libraries(demo PRIVATE numerics)

# -----------------------------
# Warnings
# -----------------------------
if (MSVC)
    target_compile_options(numerics PRIVATE /W4)
       set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /fsanitize=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fsanitize=address")
else()
    target_compile_options(numerics PRIVATE -Wall -Wextra -Wpedantic)
endif()



# -----------------------------
# Debug / Release flags
# -----------------------------
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
