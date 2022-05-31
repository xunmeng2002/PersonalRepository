SET(PROJECT_NAME "TestSharedMemoryClient")
project(${PROJECT_NAME})

add_package(src ./src)

message(STATUS "CMAKE_SYSTEM_NAME: " ${CMAKE_SYSTEM_NAME})
message(STATUS "CMAKE_CL_64: " ${CMAKE_CL_64})

add_executable(${PROJECT_NAME} ${all_file})
