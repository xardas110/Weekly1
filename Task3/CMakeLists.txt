cmake_minimum_required( VERSION 3.12.1 )

set( SRC_FILES
    Task3.cpp
)
add_link_options(/SUBSYSTEM:CONSOLE)
add_executable( Task3 WIN32
    ${HEADER_FILES} 
    ${SRC_FILES}
)

target_include_directories( Task3
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)


target_link_libraries( Task3
	../SharedLibs/Debug/SharedLib
)