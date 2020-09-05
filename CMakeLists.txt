cmake_minimum_required( VERSION 3.12.0 )

# Use solution folders to organize projects
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Make sure DLL and EXE targets go to the same directory.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/SharedLibs) # Output directory for static lib (.LIB)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # Output directory for executables (.EXE)

project( Weekly1 LANGUAGES CXX )

# Enable multithreaded builds
if( MSVC )
    add_compile_options(/MP)
endif()

add_subdirectory( Weekly1)
add_subdirectory( Task1 )
add_subdirectory( Task2 )
add_subdirectory( Task3 )
add_subdirectory( Task4 )
add_subdirectory( Task5 )

# Set the startup project.
set_directory_properties( PROPERTIES 
    VS_STARTUP_PROJECT Task1
)