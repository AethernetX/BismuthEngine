cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(core VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(INCLUDES include/Core/core.h);

add_library(core SHARED ${SRC_FILES})

# searches for a include directory
# target_include_directories(hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)