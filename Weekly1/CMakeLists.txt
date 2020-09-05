cmake_minimum_required( VERSION 3.12.1 )

set( HEADER_FILES 
   	Person.h
    	Helpers.h
    	ErrorCodes.h
)
set( SOURCE_FILES
	Person.cpp
)

add_library( SharedLib STATIC
    	${HEADER_FILES}
    	${SOURCE_FILES}
)
