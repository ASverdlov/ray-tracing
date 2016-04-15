cmake_minimum_required(VERSION 2.8)
project(ray-tracing)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(X11 REQUIRED)

file(GLOB SOURCE_FILES
     src/*.cpp
     src/geom/*.cpp
     src/rendering/*.cpp)
add_executable(ray-tracing ${SOURCE_FILES})

set(INCLUDE_DIRS
    include/geom
    include/rendering
    include)
include_directories( ${INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

set(CMAKE_CXX_FLAGS "-std=c++14")
target_link_libraries(ray-tracing ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
