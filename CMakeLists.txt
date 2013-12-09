cmake_minimum_required( VERSION 2.6 )
SET(ProjectName spaceinvaders)
project(${ProjectName})

#Get all the source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")
message("Source files:${SOURCES}")

#Go Through all the headers and add the include directories to a list
set (INCLUDE_DIRS "")
foreach (_headerFile ${HEADERS})
      get_filename_component(_dir ${_headerFile} PATH)
      list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)
message("Headers: ${HEADERS}")


link_directories(${LIBRARIES})

#set the include directories
include_directories(${INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})

#Set some compilier flags
add_definitions( "-g" )
#Set linker flags
set(GCC_COVERAGE_LINK_FLAGS		"-pthread")
set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

#Make the executable
add_executable(${ProjectName} ${SOURCES})
TARGET_LINK_LIBRARIES(${ProjectName})

