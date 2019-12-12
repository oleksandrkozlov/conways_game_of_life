cmake_minimum_required (VERSION 3.5)

project (conways_game_of_life)

set (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_SOURCE_DIR}/cmake_modules)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Release")
endif ()

set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED ON)
set (CXX_EXTENSIONS OFF)

set (CMAKE_CXX_VISIBILITY_PRESET hidden)
set (CMAKE_VISIBILITY_INLINES_HIDDEN 1)

add_compile_options (-Wall -Wextra -Wshadow)

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

include (GoogleTest)

add_subdirectory(src)
add_subdirectory(src/main)
add_subdirectory(tests)
