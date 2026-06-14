cmake_minimum_required(VERSION 3.15)

add_custom_target(common)
add_custom_target(framework)
add_custom_target(product)

add_dependencies(src common)
add_dependencies(src framework)
add_dependencies(src product)

add_subdirectory(framework)
add_subdirectory(common)
add_subdirectory(product)
