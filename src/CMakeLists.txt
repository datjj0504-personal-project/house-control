cmake_minimum_required(VERSION 3.15)
message(STATUS "Configuring src directory: ${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(framework)
add_subdirectory(common)
add_subdirectory(product)
