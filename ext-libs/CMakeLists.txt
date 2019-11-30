project(ext-libs)

cmake_policy(SET CMP0074 NEW) # CMake 3.12

include(ExternalProject)
include(ProcessorCount)

ProcessorCount(PROCESSOR_COUNT)

message("Processor count: " ${PROCESSOR_COUNT})

set(EXTERNAL_LIBS_DIR ${CMAKE_BINARY_DIR}/ext-libs/local )

set(EXTERNAL_LIBS_INCLUDE_DIR ${EXTERNAL_LIBS_DIR}/include PARENT_SCOPE)
set(EXTERNAL_LIBS_LIB_DIR ${EXTERNAL_LIBS_DIR}/lib PARENT_SCOPE)

file(MAKE_DIRECTORY ${EXTERNAL_LIBS_DIR})
file(MAKE_DIRECTORY ${EXTERNAL_LIBS_DIR}/include)
file(MAKE_DIRECTORY ${EXTERNAL_LIBS_DIR}/lib)

ExternalProject_Add(googletest_external
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest
        CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${EXTERNAL_LIBS_DIR}
        -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
        )
list(APPEND TEST_LIBS googletest_external)

add_custom_target(test-libs DEPENDS ${TEST_LIBS})