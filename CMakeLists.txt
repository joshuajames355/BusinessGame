cmake_minimum_required(VERSION 3.3)
set (CMAKE_CXX_STANDARD 14)

set(BUILD_SHARED_LIBS FALSE)

execute_process(COMMAND git submodule update --init -- external/sfml
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(external/sfml)
set(SFML_STATIC_LIBRARIES TRUE)
add_subdirectory(game)