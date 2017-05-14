cmake_minimum_required(VERSION 3.0)
project(ray-tracing)

include_directories("include/")

file(GLOB_RECURSE HEADERS "include/*.hpp")
file(GLOB_RECURSE SOURCES "src/*.cc")

add_compile_options(-std=c++14)

add_library(ray-tracing ${HEADERS} ${SOURCES})

find_package(ImageMagick COMPONENTS Magick++)
if(ImageMagick_FOUND)
  include_directories(${ImageMagick_INCLUDE_DIRS})
  message(STATUS "ImageMagic include dirs: " ${ImageMagick_INCLUDE_DIRS})
  target_link_libraries(ray-tracing ${ImageMagick_LIBRARIES})
else()
  message(FATAL_ERROR "ImageMagick is not found!")
endif()

option(ENABLE_EXAMPLES "Enable examples" ON)
if(ENABLE_EXAMPLES)
  add_subdirectory(examples)
endif()

add_subdirectory(docs)
