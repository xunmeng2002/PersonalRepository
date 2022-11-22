SET(PROJECT_NAME "TestCtpApi")
SET(APIVersion "6.3.15")
project(${PROJECT_NAME})
message("PROJECT_NAME:" ${PROJECT_NAME})

add_package(Src ./Src)
add_package(Platform ${CMAKE_SOURCE_DIR}/Source/Platform)
add_package(Error ${CMAKE_SOURCE_DIR}/Source/Error)
add_package(Event ${CMAKE_SOURCE_DIR}/Source/Event)
add_package(Utility ${CMAKE_SOURCE_DIR}/Source/Utility)
add_package(CacheList ${CMAKE_SOURCE_DIR}/Source/CacheList)
add_package(MemCache ${CMAKE_SOURCE_DIR}/Source/MemCache)
add_package(ThreadBase ${CMAKE_SOURCE_DIR}/Source/ThreadBase)
add_package(Logger ${CMAKE_SOURCE_DIR}/Source/Logger)
add_package(Jsoncpp ${CMAKE_SOURCE_DIR}/Source/Jsoncpp)

add_package(CtpGenCode ${CMAKE_SOURCE_DIR}/Source/CTP/${APIVersion})
include_package(Ctp ${CMAKE_SOURCE_DIR}/LibHeads/CTP/${APIVersion}/include)



IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	if(${CMAKE_CL_64})
		link_directories(${CMAKE_SOURCE_DIR}../Libs/CTP/${APIVersion}/win64)
	ELSE(${CMAKE_CL_64})
		link_directories(${CMAKE_SOURCE_DIR}../Libs/CTP/${APIVersion}/win32)
	endif(${CMAKE_CL_64})

	add_executable(${PROJECT_NAME} ${all_file})
	
	target_link_libraries(${PROJECT_NAME} thosttraderapi_se)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	link_directories(${CMAKE_SOURCE_DIR}../Libs/CTP/${APIVersion}/linux)
	
	add_executable(${PROJECT_NAME} ${all_file})
	
	target_link_libraries(${PROJECT_NAME} thosttraderapi_se pthread)
endif()

