cmake_minimum_required(VERSION 2.8)
PROJECT(PRACTICE)
SET(version 1.0.0)
SET(CMAKE_INSTALL_PREFIX output/pratice)
SET(PROJECT_ROOT_DIR ".")
add_subdirectory(src)
add_subdirectory(test)
