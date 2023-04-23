# Cmake version
cmake_minimum_required(VERSION 3.22)
# C++ standard
set(CMAKE_CXX_STANDARD 20)

# Build parameters
#if(NOT CMAKE_BUILD_TYPE)
#  set(CMAKE_BUILD_TYPE Debug)
#endif()
#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
#set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=address") # -fsanitize=address
#set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Project setup
project(CSapp)
set(CMAKE_BUILD_TYPE Release)

# Files and libraries
# Build OR-tools dependencies.
#set(BUILD_DEPS ON)

# Disable SCIP solver.
set(USE_SCIP OFF)

# Fetch OR-tools library and create the alias ortools::ortools.
include(FetchContent)
FetchContent_Declare(
        or-tools
        GIT_REPOSITORY https://github.com/google/or-tools.git
        GIT_TAG        v9.5
)
FetchContent_MakeAvailable(or-tools)

add_subdirectory(src)

include_directories(
    include
)

set(SOURCE_FILES
    src/Field.cpp
    src/FusionCenter.cpp
    src/Sensor.cpp
    src/CSVReader.cpp
    main.cpp)

add_executable(CSapp ${SOURCE_FILES})
target_link_libraries(CSapp ortools::ortools)