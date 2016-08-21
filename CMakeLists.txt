cmake_minimum_required(VERSION 3.0)
project(ray-tracing)

include_directories("include/")

file(GLOB_RECURSE HEADERS "include/*.hpp")
file(GLOB_RECURSE SOURCES "src/*.cc")

add_compile_options(-std=c++14)
add_library(ray-tracing ${HEADERS} ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

if(OPENGL_FOUND AND GLUT_FOUND)
  include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
  target_link_libraries(ray-tracing ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
else(OPENGL_FOUND AND GLUT_FOUND)
  message(WARNING "OpenGL or GLUT is not found")
endif(OPENGL_FOUND AND GLUT_FOUND)
