cmake_minimum_required(VERSION 3.14)
project(know-algo)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(ext-libs)

include_directories(${EXTERNAL_LIBS_INCLUDE_DIR})
link_directories(${EXTERNAL_LIBS_LIB_DIR})

include_directories(include)
add_subdirectory(src)
add_subdirectory(tests)
