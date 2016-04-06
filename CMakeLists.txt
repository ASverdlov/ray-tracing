cmake_minimum_required(VERSION 2.8)

project(ray-tracing)
add_executable(ray-tracing src/main.cpp src/renderer.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(X11 REQUIRED)
include_directories( include ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(ray-tracing ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
