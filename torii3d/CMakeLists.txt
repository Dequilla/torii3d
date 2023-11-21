cmake_minimum_required(VERSION 3.16)

message("Building torii3d")

#####################################
# Variables
#####################################

set(LIBRARY_NAME torii3d)

set(LIBRARY_FOLDER ${CMAKE_SOURCE_DIR}/${LIBRARY_NAME}/source)
set(LIBRARY_INCLUDE_FOLDER ${CMAKE_SOURCE_DIR}/${LIBRARY_NAME}/include)

if (MSVC OR WIN32)
    add_compile_definitions(__WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif (UNIX)
    add_compile_definitions(__unix__)
endif ()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++2a")

project(
    ${LIBRARY_NAME} 
    VERSION 0.1
    DESCRIPTION "Torii3d library."    
    LANGUAGES CXX
)

#####################################
# Source files
#####################################

set(FILES_LIBRARY
    ${LIBRARY_FOLDER}/math.cpp
    ${LIBRARY_FOLDER}/model.cpp
    ${LIBRARY_FOLDER}/display.cpp
    ${LIBRARY_FOLDER}/settings.cpp
    ${LIBRARY_FOLDER}/event.cpp
    ${LIBRARY_FOLDER}/utility.cpp
    ${LIBRARY_FOLDER}/logger.cpp
    ${LIBRARY_FOLDER}/color.cpp
    
    ${LIBRARY_FOLDER}/resource/resource.cpp
    ${LIBRARY_FOLDER}/resource/text_document.cpp

    ${LIBRARY_FOLDER}/ecs/entity.cpp
    ${LIBRARY_FOLDER}/ecs/component.cpp 
    ${LIBRARY_FOLDER}/ecs/system.cpp
    ${LIBRARY_FOLDER}/ecs/world.cpp

    ${LIBRARY_FOLDER}/platform/display_impl.cpp

    ${LIBRARY_FOLDER}/platform/OpenGL/impl_opengl_definitions.cpp
    ${LIBRARY_FOLDER}/platform/OpenGL/impl_opengl.cpp
    ${LIBRARY_FOLDER}/platform/OpenGL/mesh_impl_opengl.cpp

    ${LIBRARY_FOLDER}/platform/x11/display_impl_x11.cpp
    ${LIBRARY_FOLDER}/platform/x11/keycodes_x11.cpp

    ${LIBRARY_FOLDER}/torii.cpp
)
message("Files library: ${FILES_LIBRARY}")

######################################
# Libraries 
######################################

find_package(X11)
if(NOT X11_FOUND)
    message(SEND_ERROR "Not found: X11")
endif()

find_package(OpenGL)
if(NOT OPENGL_FOUND)
    message(SEND_ERROR "Not found: OpenGL")
endif()

set(
    LIBRARIES_TO_LINK
    ${OPENGL_LIBRARIES}
    ${X11_X11_LIB}
)

######################################
# Definitions
######################################

# Library
add_library(${LIBRARY_NAME} SHARED ${FILES_LIBRARY}) 
target_include_directories(${LIBRARY_NAME} PRIVATE ${LIBRARY_INCLUDE_FOLDER})
target_link_libraries(${LIBRARY_NAME} ${LIBRARIES_TO_LINK})
set_property(TARGET ${LIBRARY_NAME} PROPERTY CXX_STANDARD 20)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    message("Debug build!")
    target_compile_definitions(${LIBRARY_NAME} PRIVATE _DEBUG)
else()
    message("Release build!")
    target_compile_definitions(${LIBRARY_NAME} PRIVATE _RELEASE)
endif()

# Export symbols
set(TORII3D_LIB ${LIBRARY_NAME} ${LIBRARIES_TO_LINK} PARENT_SCOPE)
set(TORII3D_INCLUDE ${LIBRARY_INCLUDE_FOLDER} PARENT_SCOPE)