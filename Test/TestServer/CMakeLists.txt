﻿SET(PROJECT_NAME "TestServer")
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
add_package(Encode ${CMAKE_SOURCE_DIR}/Source/Encode)
add_package(Jsoncpp ${CMAKE_SOURCE_DIR}/Source/Jsoncpp)

add_package(SocketInit ${CMAKE_SOURCE_DIR}/Source/SocketInit)
add_package(Udp ${CMAKE_SOURCE_DIR}/Source/Udp)
add_package(TcpBase ${CMAKE_SOURCE_DIR}/Source/Tcp/TcpBase)
add_package(TcpSelect ${CMAKE_SOURCE_DIR}/Source/Tcp/TcpSelect)
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
add_package(TcpEpoll ${CMAKE_SOURCE_DIR}/Source/Tcp/TcpEpoll)
endif()
if (CMAKE_SYSTEM_NAME MATCHES "Windows")
add_package(TcpIOCP ${CMAKE_SOURCE_DIR}/Source/Tcp/TcpIOCP)
endif()

include_package(Zlib ${CMAKE_SOURCE_DIR}/LibHeads/Zlib/1.2.11/include)
include_package(ProtoBuf ${CMAKE_SOURCE_DIR}/LibHeads/ProtoBuf/3.21.1/include)


IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	link_directories(${CMAKE_SOURCE_DIR}/../Libs/Zlib/1.2.11/win64)
	add_executable(${PROJECT_NAME} ${all_file})
	target_link_libraries(${PROJECT_NAME} debug zlibstaticd.lib)
	target_link_libraries(${PROJECT_NAME} optimized zlibstatic.lib)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	link_directories(${CMAKE_SOURCE_DIR}/../Libs/Zlib/1.2.11/linux64/Debug)
	add_executable(${PROJECT_NAME} ${all_file})
	target_link_libraries(${PROJECT_NAME} pthread z)
endif()
