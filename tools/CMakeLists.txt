cmake_minimum_required(VERSION 3.15)
message(STATUS "Configuring tools directory: ${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tools)
add_subdirectory(generate-uuid)