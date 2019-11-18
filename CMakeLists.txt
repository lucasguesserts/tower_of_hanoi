CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wextra -ansi -pedantic -fprofile-arcs -ftest-coverage -lm")

set(LOG_DIR "${CMAKE_BINARY_DIR}/log/")
file(MAKE_DIRECTORY "${LOG_DIR}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DLOG_OUTPUT=\\\"${LOG_DIR}\\\"")

project(tower_of_hanoi)
set(VERSION_MAJOR "0")
set(VERSION_MINOR "0")
set(VERSION_PATCH "0")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()

message("\n")
message("---- Project ${PROJECT_NAME} ----")
message("Version		= ${VERSION}")
message("C compiler 	= ${CMAKE_C_COMPILER}")
message("Compiler flags	= ${CMAKE_C_FLAGS}")
message("\n")

add_subdirectory(TestLib)
add_subdirectory(TestLibTest)
add_subdirectory(TowerOfHanoiLib)
add_subdirectory(TowerOfHanoiLibTest)
add_subdirectory(InteractiveTowerOfHanoi)
add_subdirectory(OptimizedAlgorithmTowerOfHanoi)