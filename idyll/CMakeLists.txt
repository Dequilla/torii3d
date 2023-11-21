cmake_minimum_required(VERSION 3.16)

message("Building idyll")

#####################################
# Variables
#####################################

set(IDYLL_NAME idyll)

set(IDYLL_SOURCE_FOLDER ${CMAKE_SOURCE_DIR}/${IDYLL_NAME}/source)
set(IDYLL_INCLUDE_FOLDER ${CMAKE_SOURCE_DIR}/${IDYLL_NAME}/include)
message("Idyll source dir: " ${IDYLL_SOURCE_FOLDER})
message("Idyll include dir: " ${IDYLL_INCLUDE_FOLDER})

if (MSVC OR WIN32)
    add_compile_definitions(__WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif (UNIX)
    add_compile_definitions(__unix__)
endif ()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++2a")

project(
    ${IDYLL_NAME} 
    VERSION 0.1
    DESCRIPTION "Idyll testing lib."    
    LANGUAGES CXX
)

#####################################
# Source files
#####################################

set(IDYLL_FILES_LIBRARY
    ${IDYLL_SOURCE_FOLDER}/idyll.cpp
)

######################################
# Definitions
######################################

# Library
add_library(${IDYLL_NAME} SHARED ${IDYLL_FILES_LIBRARY})
target_include_directories(${IDYLL_NAME} PRIVATE ${IDYLL_INCLUDE_FOLDER})
set_property(TARGET ${IDYLL_NAME} PROPERTY CXX_STANDARD 20)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    message("Debug build!")
    target_compile_definitions(${IDYLL_NAME} PRIVATE _DEBUG)
else()
    message("Release build!")
    target_compile_definitions(${IDYLL_NAME} PRIVATE _RELEASE)
endif()

# Exporting symbols
set(IDYLL_INCLUDE ${IDYLL_INCLUDE_FOLDER} PARENT_SCOPE)
set(IDYLL_LIB ${IDYLL_NAME} PARENT_SCOPE)