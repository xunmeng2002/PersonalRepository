SET(PROJECT_NAME "TestOpenSSL")
project(${PROJECT_NAME})


add_package(src ./src)
add_package(OpenSSL ${CMAKE_SOURCE_DIR}/Source/OpenSSL)

include_package(OpenSSL ${CMAKE_SOURCE_DIR}/Libs/openssl/3.0.5/include)


message(STATUS "CMAKE_SYSTEM_NAME: " ${CMAKE_SYSTEM_NAME})
message(STATUS "CMAKE_CL_64: " ${CMAKE_CL_64})
message(STATUS "Windows Lib")
if(${CMAKE_CL_64})
	message(STATUS "CMAKE_CL_64")
	link_directories(${CMAKE_SOURCE_DIR}/Libs/openssl/3.0.5/win64_2022)
ELSE(${CMAKE_CL_64})
	message(STATUS "CMAKE_CL_32")
	link_directories(${CMAKE_SOURCE_DIR}/Libs/openssl/3.0.5/win32_2022)
endif(${CMAKE_CL_64})

add_executable(${PROJECT_NAME} ${all_file})
target_link_libraries(${PROJECT_NAME} libcrypto_static.lib libssl_static.lib WS2_32.LIB)
