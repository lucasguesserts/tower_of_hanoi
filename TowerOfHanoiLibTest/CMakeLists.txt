project(TowerOfHanoiLibTest)

include_directories(${CMAKE_SOURCE_DIR}/TestLib/include)
include_directories(${CMAKE_SOURCE_DIR}/TowerOfHanoiLib/include)
include_directories(${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/include)

file(GLOB ${PROJECT_NAME}_sources ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/*.c)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_sources})

target_link_libraries(${PROJECT_NAME} TestLib)
target_link_libraries(${PROJECT_NAME} TowerOfHanoiLib)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})