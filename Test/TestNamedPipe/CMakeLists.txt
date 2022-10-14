SET(PROJECT_NAME "TestNamedPipe")
project(${PROJECT_NAME})
message("PROJECT_NAME:" ${PROJECT_NAME})

add_package(Src ./Src)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
add_executable(${PROJECT_NAME} ${all_file})
endif()
