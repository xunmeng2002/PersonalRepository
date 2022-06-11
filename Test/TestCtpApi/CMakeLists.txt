SET(PROJECT_NAME "TestCtpApi")
SET(APIVersion "6.3.15")
project(${PROJECT_NAME})


add_package(src ./src)
add_package(Platform ${CMAKE_SOURCE_DIR}/Source/Platform)
add_package(Event ${CMAKE_SOURCE_DIR}/Source/Event)
add_package(Utility ${CMAKE_SOURCE_DIR}/Source/Utility)
add_package(CacheList ${CMAKE_SOURCE_DIR}/Source/CacheList)
add_package(MemCache ${CMAKE_SOURCE_DIR}/Source/MemCache)
add_package(ThreadBase ${CMAKE_SOURCE_DIR}/Source/ThreadBase)
add_package(Logger ${CMAKE_SOURCE_DIR}/Source/Logger)
add_package(jsoncpp ../../source/jsoncpp)

add_package(Ctp ${CMAKE_SOURCE_DIR}/Libs/CTP/${APIVersion}/include)
add_package(CtpGenCode ${CMAKE_SOURCE_DIR}/Source/CTP/${APIVersion})


message(STATUS "CMAKE_SYSTEM_NAME: " ${CMAKE_SYSTEM_NAME})
message(STATUS "CMAKE_CL_64: " ${CMAKE_CL_64})
IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	message(STATUS "Windows Lib")
	if(${CMAKE_CL_64})
		link_directories(${CMAKE_SOURCE_DIR}/Libs/CTP/${APIVersion}/win64)
	ELSE(${CMAKE_CL_64})
		link_directories(${CMAKE_SOURCE_DIR}/Libs/CTP/${APIVersion}/win32)
	endif(${CMAKE_CL_64})

	add_executable(${PROJECT_NAME} ${all_file})
	
	target_link_libraries(${PROJECT_NAME} thosttraderapi_se)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	message(STATUS "Linux Lib")
	link_directories(${CMAKE_SOURCE_DIR}/Libs/CTP/${APIVersion}/linux)
	
	add_executable(${PROJECT_NAME} ${all_file})
	
	target_link_libraries(${PROJECT_NAME} pthread thosttraderapi_se)
endif()

