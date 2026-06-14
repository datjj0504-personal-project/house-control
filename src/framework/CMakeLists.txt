cmake_minimum_required(VERSION 3.15)
message(STATUS "Configuring framework directory: ${CMAKE_CURRENT_SOURCE_DIR}")

add_custom_target(execute)
add_custom_target(providers)
add_custom_target(services)

add_dependencies(framework execute)
add_dependencies(framework providers)
add_dependencies(framework services)

add_subdirectory(execute)
