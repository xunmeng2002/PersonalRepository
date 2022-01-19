SET(PROJECT_NAME "TestServer")
project(${PROJECT_NAME})


add_package(src ./src)
add_package(Event ${CMAKE_SOURCE_DIR}/Source/Event)
add_package(Utility ${CMAKE_SOURCE_DIR}/Source/Utility)
add_package(TimeUtility ${CMAKE_SOURCE_DIR}/Source/TimeUtility)
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

message(STATUS "CMAKE_CL_64: " ${CMAKE_CL_64})
if(${CMAKE_CL_64})
	link_directories(${CMAKE_SOURCE_DIR}/Libs/Zlib/1.2.11/win64)
ELSE(${CMAKE_CL_64})
	link_directories(${CMAKE_SOURCE_DIR}/Libs/Zlib/1.2.11/win32)
endif(${CMAKE_CL_64})

add_executable(${PROJECT_NAME} ${all_file})
target_link_libraries(${PROJECT_NAME} debug zlibstaticd.lib)
target_link_libraries(${PROJECT_NAME} optimized zlibstatic.lib)
