
# Using minimum CMake version 3.13 to prevent issues with the SWIG include
# directories propagation happening with CMake 3.12 and prior

cmake_minimum_required(VERSION 3.13)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
    cmake_policy(SET CMP0048 NEW)
endif()

# SWIG: use standard target name.
if(POLICY CMP0078)
  cmake_policy(SET CMP0078 NEW)
endif()

# SWIG: use SWIG_MODULE_NAME property.
if(POLICY CMP0086)
  cmake_policy(SET CMP0086 NEW)
endif()

###############################################################################
# Library for types defined in ControllerCommand IDL
###############################################################################

message(STATUS "Configuring python wrapper for types in ControllerCommand...")

###############################################################################
# Type library on C++

project(ControllerCommand)

FIND_PACKAGE(fastcdr REQUIRED)
FIND_PACKAGE(fastrtps REQUIRED)


set(${PROJECT_NAME}_FILES
    ControllerCommand.cxx
    ControllerCommandPubSubTypes.cxx
    )

INCLUDE_DIRECTORIES()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#Create library for C++ types
add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC fastcdr fastrtps)

###############################################################################
# Python bindings for type

project(ControllerCommandWrapper)

FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})
SET(CMAKE_SWIG_FLAGS "")

FIND_PACKAGE(Python3 COMPONENTS Interpreter Development REQUIRED)
set(PYTHON_INCLUDE_PATH ${Python3_INCLUDE_DIRS})
set(PYTHON_EXECUTABLE ${Python3_EXECUTABLE})
set(PYTHON_LIBRARIES ${Python3_LIBRARY})

INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

FIND_PACKAGE(fastcdr REQUIRED)
FIND_PACKAGE(fastrtps REQUIRED)

set(${PROJECT_NAME}_MODULE
    ControllerCommand
    )

set(${PROJECT_NAME}_FILES
    ${${PROJECT_NAME}_MODULE}.i
    )

SET_SOURCE_FILES_PROPERTIES(
    ${${PROJECT_NAME}_FILES}
    PROPERTIES CPLUSPLUS ON
    USE_TARGET_INCLUDE_DIRECTORIES TRUE
    )

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}
    )

SWIG_ADD_LIBRARY(${PROJECT_NAME}
    TYPE SHARED
    LANGUAGE python
    SOURCES ${${PROJECT_NAME}_FILES})

SWIG_LINK_LIBRARIES(${PROJECT_NAME}
    ${PYTHON_LIBRARIES}
    fastrtps
    ControllerCommand
    )

# Find the installation path
execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "from distutils import sysconfig; print(sysconfig.get_python_lib(plat_specific=True, prefix='${CMAKE_INSTALL_PREFIX}'))"
    OUTPUT_VARIABLE _ABS_PYTHON_MODULE_PATH
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )

get_filename_component (_ABS_PYTHON_MODULE_PATH ${_ABS_PYTHON_MODULE_PATH} ABSOLUTE)
file (RELATIVE_PATH _REL_PYTHON_MODULE_PATH ${CMAKE_INSTALL_PREFIX} ${_ABS_PYTHON_MODULE_PATH})
SET (PYTHON_MODULE_PATH
    ${_REL_PYTHON_MODULE_PATH}
    )

# Install
INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/_${PROJECT_NAME}.so DESTINATION ${PYTHON_MODULE_PATH} )
INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/lib${${PROJECT_NAME}_MODULE}.so DESTINATION ${PYTHON_MODULE_PATH} )
INSTALL ( FILES ${CMAKE_CURRENT_BINARY_DIR}/${${PROJECT_NAME}_MODULE}.py DESTINATION ${PYTHON_MODULE_PATH} )

