####################
#      Global      #
####################

cmake_minimum_required(VERSION 3.12)
# set(CMAKE_CXX_STANDARD 17)

#####################
#      Project      #
#####################

# Project variables
set(LOCAL_PROJECT_NAME        "console_app")
set(LOCAL_PROJECT_VERSION     "0.0.1")
set(LOCAL_PROJECT_DESCRIPTION "Description")

# Define source and header directories (use absolute paths)
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# Automatically find all .cpp files in the src/ directory
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

# Automatically find all .h files in the include/ directory
file(GLOB_RECURSE HEADERS "${INCLUDE_DIR}/*.h")

# Debug: Output the source files found
message(STATUS "Source files: ${SOURCES}")

# Include directories for header files
include_directories(${INCLUDE_DIR})

# If no source files are found, throw an error
if(NOT SOURCES)
    message(FATAL_ERROR "No source files found in ${SRC_DIR}")
endif()

# Compiler definitions
set(DEFINES

)

# Compiler options
set(OPTIONS

)

# Project setup
project(${LOCAL_PROJECT_NAME}
        VERSION ${LOCAL_PROJECT_VERSION}
        DESCRIPTION ${LOCAL_PROJECT_DESCRIPTION}
        LANGUAGES CXX)

add_executable(${LOCAL_PROJECT_NAME} ${SOURCES})


####################
#   Dependencies   #
####################

