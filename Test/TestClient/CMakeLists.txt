SET(PROJECT_NAME "TestClient")
project(${PROJECT_NAME})


add_package(src ./src)
add_package(Platform ${CMAKE_SOURCE_DIR}/Source/Platform)
add_package(Event ${CMAKE_SOURCE_DIR}/Source/Event)
add_package(Utility ${CMAKE_SOURCE_DIR}/Source/Utility)
add_package(CacheList ${CMAKE_SOURCE_DIR}/Source/CacheList)
add_package(MemCache ${CMAKE_SOURCE_DIR}/Source/MemCache)
add_package(ThreadBase ${CMAKE_SOURCE_DIR}/Source/ThreadBase)
add_package(Logger ${CMAKE_SOURCE_DIR}/Source/Logger)

add_package(SocketInit ${CMAKE_SOURCE_DIR}/Source/SocketInit)
add_package(Udp ${CMAKE_SOURCE_DIR}/Source/Udp)
add_package(TcpBase ${CMAKE_SOURCE_DIR}/Source/Tcp/TcpBase)
add_package(TcpSelect ${CMAKE_SOURCE_DIR}/Source/Tcp/TcpSelect)
if (CMAKE_SYSTEM_NAME MATCHES "Windows")
add_package(TcpIOCP ${CMAKE_SOURCE_DIR}/Source/Tcp/TcpIOCP)
endif()

include_package(Zlib ${CMAKE_SOURCE_DIR}/Libs/Zlib/1.2.11/include)




message(STATUS "CMAKE_SYSTEM_NAME: " ${CMAKE_SYSTEM_NAME})
message(STATUS "CMAKE_CL_64: " ${CMAKE_CL_64})
IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	message(STATUS "Windows Lib")
	if(${CMAKE_CL_64})
		message(STATUS "CMAKE_CL_64")
		message(STATUS ${CMAKE_SOURCE_DIR}/Libs/Zlib/1.2.11/win64)
		link_directories(${CMAKE_SOURCE_DIR}/Libs/Zlib/1.2.11/win64)
	ELSE(${CMAKE_CL_64})
		message(STATUS "CMAKE_CL_32")
		link_directories(${CMAKE_SOURCE_DIR}/Libs/Zlib/1.2.11/win32)
	endif(${CMAKE_CL_64})

	add_executable(${PROJECT_NAME} ${all_file})

	target_link_libraries(${PROJECT_NAME} debug zlibstaticd.lib)
	target_link_libraries(${PROJECT_NAME} optimized zlibstatic.lib)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	message(STATUS "Linux Lib")
	link_directories(${CMAKE_SOURCE_DIR}/Libs/Zlib/1.2.11/linux64/Debug)
	add_executable(${PROJECT_NAME} ${all_file})
	target_link_libraries(${PROJECT_NAME} pthread z)
endif()
