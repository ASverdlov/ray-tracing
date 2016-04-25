cmake_minimum_required(VERSION 2.8)

project(ray-tracing)

# General
###########################################
add_definitions(-std=c++14)
add_definitions(-Wextra)

# Google Mock & Test
###########################################
set(GMOCK_ROOT "googletest")
add_subdirectory(${GMOCK_ROOT})
include_directories(${GMOCK_ROOT}/googlemock/include)
include_directories(${GMOCK_ROOT}/googletest/include)

# Main executable
###########################################
set(EXECUTABLE_NAME "ray-tracing")
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

file(GLOB SOURCE_FILES
     src/*.cpp
     src/geom/*.cpp
     src/rendering/*.cpp)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

set(INCLUDE_DIRS
    include/geometry
    include/rendering
    include)
include_directories( ${INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

target_link_libraries(ray-tracing ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

# Tests
###########################################
set(TEST_EXECUTABLE_NAME "tests")

file(GLOB TEST_SOURCE_FILES "test/*.cpp")

add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SOURCE_FILES})

target_link_libraries(${TEST_EXECUTABLE_NAME} gmock gtest pthread)
