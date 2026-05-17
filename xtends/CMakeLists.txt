cmake_minimum_required(VERSION 3.15)
message(STATUS "Configuring xtends directory: ${CMAKE_CURRENT_SOURCE_DIR}")

# Auto-add any subdirectories that contain a CMakeLists.txt
# file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
# foreach(child ${children})
# 	if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${child}" AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${child}/CMakeLists.txt")
# 		message(STATUS "  Adding subdirectory: ${child}")
# 		add_subdirectory(${child} ${CMAKE_CURRENT_BINARY_DIR}/${child})
# 	endif()
# endforeach()
