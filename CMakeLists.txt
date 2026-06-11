cmake_minimum_required(VERSION 3.20)

project(Numerics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE NUMERICS_SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_library(numerics STATIC ${NUMERICS_SOURCES})

target_include_directories(numerics PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(demo
    ${PROJECT_SOURCE_DIR}/app/main.cpp
)

target_link_libraries(demo PRIVATE numerics)

# ASAN needs the AddressSanitizer component installed in VS
option(USE_ASAN "Enable AddressSanitizer" OFF)
if (MSVC)
    target_compile_options(numerics PRIVATE /W3)
    target_compile_options(demo PRIVATE /W3)
    if (USE_ASAN)
        target_compile_options(numerics PRIVATE /fsanitize=address)
        target_compile_options(demo PRIVATE /fsanitize=address)
    endif()
else()
    target_compile_options(numerics PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(demo PRIVATE -Wall -Wextra -Wpedantic)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)