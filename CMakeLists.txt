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
  target_link_libraries(ray-tracing ${ImageMagick_LIBRARIES})
else()
  message(WARNING "ImageMagick is not found!")
endif()


add_subdirectory(docs)
add_subdirectory(examples)
