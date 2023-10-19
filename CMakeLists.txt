cmake_minimum_required(VERSION 3.1)

#####################################
# Variables
#####################################

set(PROGRAM_NAME torii)
set(LIBRARY_NAME torii3d)

set(SOURCE_FOLDER ${PROGRAM_NAME}/source)
set(PROGRAM_INCLUDE_FOLDER ${PROGRAM_NAME}/include)

set(LIBRARY_FOLDER ${LIBRARY_NAME}/source)
set(LIBRARY_INCLUDE_FOLDER ${LIBRARY_NAME}/include)

if (MSVC OR WIN32)
    add_compile_definitions(__WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif (UNIX)
    add_compile_definitions(__unix__)
endif ()

project(
    ${PROGRAM_NAME} 
    VERSION 0.1
    DESCRIPTION "Practicing CPP."    
    LANGUAGES CXX
)

#####################################
# Source files
#####################################

set(FILES_PROGRAM 
    ${SOURCE_FOLDER}/main.cpp
)
message("Files program: ${FILES_PROGRAM}")

set(FILES_LIBRARY
    ${LIBRARY_FOLDER}/math.cpp
    ${LIBRARY_FOLDER}/model.cpp
    ${LIBRARY_FOLDER}/display.cpp
    ${LIBRARY_FOLDER}/settings.cpp
    ${LIBRARY_FOLDER}/event.cpp
    ${LIBRARY_FOLDER}/utility.cpp

    ${LIBRARY_FOLDER}/platform/display_impl.cpp

    ${LIBRARY_FOLDER}/platform/x11/display_impl_x11.cpp
    ${LIBRARY_FOLDER}/platform/x11/keycodes_x11.cpp
)
message("Files library: ${FILES_LIBRARY}")

######################################
# Libraries 
######################################

find_package(X11)
if(NOT X11_FOUND)
    message(SEND_ERROR "Not found: X11")
endif()

######################################
# Definitions
######################################

# Library
add_library(${LIBRARY_NAME} SHARED ${FILES_LIBRARY})
target_include_directories(${LIBRARY_NAME} PRIVATE ${LIBRARY_INCLUDE_FOLDER})
target_link_libraries(${LIBRARY_NAME} ${X11_X11_LIB})
set_property(TARGET ${LIBRARY_NAME} PROPERTY CXX_STANDARD 20)

# Executable
add_executable(${PROGRAM_NAME} ${FILES_PROGRAM})
target_include_directories(${PROGRAM_NAME} PRIVATE ${LIBRARY_INCLUDE_FOLDER} ${PROGRAM_INCLUDE_FOLDER})
target_link_libraries(${PROGRAM_NAME} ${LIBRARY_NAME})
set_property(TARGET ${PROGRAM_NAME} PROPERTY CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g -O3")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall -O0")