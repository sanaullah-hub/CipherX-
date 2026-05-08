cmake_minimum_required(VERSION 3.20)
project(CipherX 
    VERSION 1.0.0
    DESCRIPTION "A C++ Game Project"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Enable testing
enable_testing()

# Add compiler warnings
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Main game executable
add_executable(cipherx
    src/main.cpp
    src/game.cpp
    src/game.h
)

target_include_directories(cipherx PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Optional: Add external libraries
# Uncomment when you add dependencies
# find_package(SDL2 REQUIRED)
# target_link_libraries(cipherx PRIVATE SDL2::SDL2)

# Code quality tools configuration
# clang-format
add_custom_target(format
    COMMAND clang-format -i -style=file src/*.cpp src/*.h
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running clang-format"
)

# clang-tidy
add_custom_target(tidy
    COMMAND clang-tidy -p ${CMAKE_BINARY_DIR} src/*.cpp
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running clang-tidy"
)

# cppcheck
add_custom_target(cppcheck
    COMMAND cppcheck --enable=all --suppress=missingIncludeSystem src/
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running cppcheck"
)

# Combined quality check target
add_custom_target(quality DEPENDS format tidy cppcheck
    COMMENT "Running all code quality checks"
)
