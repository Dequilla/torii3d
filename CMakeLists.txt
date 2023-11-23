cmake_minimum_required(VERSION 3.16)

#####################################
# Variables
#####################################

set(PROGRAM_NAME torii)

set(SOURCE_FOLDER ${PROGRAM_NAME}/source)
set(PROGRAM_INCLUDE_FOLDER ${PROGRAM_NAME}/include)

if (MSVC OR WIN32)
    add_compile_definitions(__WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif (UNIX)
    add_compile_definitions(__unix__)
endif ()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++2a")

project(
    ${PROGRAM_NAME} 
    VERSION 0.1
    DESCRIPTION "Torii engine."    
    LANGUAGES CXX
)

option(BUILD_TESTS "Build for tests." OFF)

#####################################
# Source files
#####################################

set(FILES_PROGRAM 
    ${SOURCE_FOLDER}/main.cpp
)
message("Files program: ${FILES_PROGRAM}")

######################################
# Definitions
######################################

add_subdirectory(idyll ${CMAKE_BINARY_DIR}/idyll)
message("Idyll include: " ${IDYLL_INCLUDE})
message("Idyll lib: " ${IDYLL_LIB})

add_subdirectory(torii3d ${CMAKE_BINARY_DIR}/torii3d)
message("Torii3d include: " ${TORII3D_INCLUDE})
message("Torii3d lib: " ${TORII3D_LIB})

# Executable
add_executable(${PROGRAM_NAME} ${FILES_PROGRAM})
target_include_directories(${PROGRAM_NAME} PRIVATE ${PROGRAM_INCLUDE_FOLDER} ${IDYLL_INCLUDE} ${TORII3D_INCLUDE})
target_link_libraries(${PROGRAM_NAME} ${IDYLL_LIB} ${TORII3D_LIB})
set_property(TARGET ${PROGRAM_NAME} PROPERTY CXX_STANDARD 20)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    message("Debug build!")
    target_compile_definitions(${PROGRAM_NAME} PRIVATE _DEBUG)
else()
    message("Release build!")
    target_compile_definitions(${PROGRAM_NAME} PRIVATE _RELEASE)
endif()

if(BUILD_TESTS)
    message("Building for tests!")
    target_compile_definitions(${PROGRAM_NAME} PRIVATE _RUN_TESTS)
endif()

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g -O3")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall -O0")