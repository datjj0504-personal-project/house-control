cmake_minimum_required(VERSION 3.15)

# Project name
project(house-control LANGUAGES CXX)

include(cmake/common.cmake)

include_directories(src/common)
include_directories(src/framework)
include_directories(src/product)

include(cmake/output.cmake)

add_custom_target(src)
add_custom_target(tools)
add_custom_target(xtends)


add_subdirectory(src)
add_subdirectory(tools)
add_subdirectory(xtends)

message("#########################################")
message("CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")
message("CMAKE_CXX_STANDARD_REQUIRED: ${CMAKE_CXX_STANDARD_REQUIRED}")
message("CMAKE_CXX_EXTENSIONS: ${CMAKE_CXX_EXTENSIONS}")
message("CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
message("CMAKE_CXX_FLAGS_RELWITHDEBINFO: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message("CMAKE_CXX_FLAGS_MINSIZEREL: ${CMAKE_CXX_FLAGS_MINSIZEREL}")
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message("MY_PROJECT_BUILD_TYPE: ${MY_PROJECT_BUILD_TYPE}")
message("MY_OUTPUT_DIR: ${MY_OUTPUT_DIR}")
message("Output directory: ${MY_OUTPUT_DIR}/${MY_PROJECT_BUILD_TYPE}")
message("CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("#########################################")