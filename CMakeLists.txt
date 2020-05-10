cmake_minimum_required(VERSION 3.4.2)

project(GenericSolver)


set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")

file(GLOB source_files
    #grab src dir
    "${PROJECT_SOURCE_DIR}/src/**/*.h"
    "${PROJECT_SOURCE_DIR}/src/**/*.cpp"

    #grab main
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(
    ${PROJECT_NAME}
    ${source_files}
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

#target_link_libraries(
#    ${PROJECT_NAME}
#    ${PROJECT_SOURCE_DIR}/lib/libtwCSdk.so.2.1.2
#    ${PROJECT_SOURCE_DIR}/lib/libssl.so.1.0.0
#    ${PROJECT_SOURCE_DIR}/lib/libcrypto.so.1.0.0
#)
