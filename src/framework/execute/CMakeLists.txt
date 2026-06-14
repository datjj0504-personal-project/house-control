cmake_minimum_required(VERSION 3.15)

# Project Name
#	- [Module]: main-server
set(MY_MODULE_NAME "main-server")
project(${MY_MODULE_NAME} VERSION 0.1.0)
add_executable(${MY_MODULE_NAME})
target_sources(${MY_MODULE_NAME} PRIVATE main.cpp)


