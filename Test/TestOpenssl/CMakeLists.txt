SET(PROJECT_NAME "TestOpenssl")
project(${PROJECT_NAME})
message("PROJECT_NAME:" ${PROJECT_NAME})

add_package(Src ./Src)
add_package(Openssl ${CMAKE_SOURCE_DIR}/Source/Openssl)

include_package(OpensslLib ${CMAKE_SOURCE_DIR}/LibHeads/openssl/3.0.5/include)
IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	if(${CMAKE_CL_64})
		link_directories(${CMAKE_SOURCE_DIR}/../Libs/openssl/3.0.5/win64_2022)
	ELSE(${CMAKE_CL_64})
		link_directories(${CMAKE_SOURCE_DIR}/../Libs/openssl/3.0.5/win32_2022)
	endif(${CMAKE_CL_64})
	add_executable(${PROJECT_NAME} ${all_file})
	
	target_link_libraries(${PROJECT_NAME} libcrypto_static.lib libssl_static.lib WS2_32.LIB)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	add_executable(${PROJECT_NAME} ${all_file})
	target_link_libraries(${PROJECT_NAME} crypto ssl pthread dl)
endif()


