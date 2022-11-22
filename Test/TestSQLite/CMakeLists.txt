SET(PROJECT_NAME "TestSQLite")
project(${PROJECT_NAME})
message("PROJECT_NAME:" ${PROJECT_NAME})

add_package(Src ./Src)
add_package(Utility ${CMAKE_SOURCE_DIR}/Source/Utility)


include_package(SQLite ${CMAKE_SOURCE_DIR}/LibHeads/SQLite/3.36.0/include)
IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	if(${CMAKE_CL_64})
		link_directories(${CMAKE_SOURCE_DIR}../Libs/SQLite/3.36.0/win64)
	ELSE(${CMAKE_CL_64})
		link_directories(${CMAKE_SOURCE_DIR}../Libs/SQLite/3.36.0/win32)
	endif(${CMAKE_CL_64})

	add_executable(${PROJECT_NAME} ${all_file})

	target_link_libraries(${PROJECT_NAME} sqlite3.lib)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	link_directories(${CMAKE_SOURCE_DIR}../Libs/SQLite/3.36.0/linux)
	
	add_executable(${PROJECT_NAME} ${all_file})
	
	target_link_libraries(${PROJECT_NAME} sqlite3 pthread dl)
endif()