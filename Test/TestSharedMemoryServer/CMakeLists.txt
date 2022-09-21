SET(PROJECT_NAME "TestSharedMemoryServer")
project(${PROJECT_NAME})
message("PROJECT_NAME:" ${PROJECT_NAME})

add_package(Src ./Src)


add_executable(${PROJECT_NAME} ${all_file})
