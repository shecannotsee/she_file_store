#############################################################
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#############################################################
set(PROJECT_NAME "sheFileStore")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

#############################################################
get_filename_component(a_demo ${CMAKE_SOURCE_DIR} DIRECTORY)
message(STATUS "a_demo's path:${a_demo}")

#############################################################

# include
include_directories(
        ${LOCAL_INCLUDE}
        ${PROTOBUF_INCLUDE}
        ${GRPC_INCLUDE}
)
# lib
link_directories(
        ${LOCAL_LIB}
        ${PROTOBUF_LIB}
        ${GRPC_LIB}
)

#############################################################
# Compatibility test
#set(target "sheFileStore")
set(target "test")
if (target STREQUAL "test")
    file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/test/*")
elseif(target STREQUAL "sheFileStore")
    file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/src/*")
else()
    message(STATUS "CMakeLists.txt error")
endif ()
add_executable(${PROJECT_NAME}
        ${SRC}
        )

#################################################################
# link
target_link_libraries(${PROJECT_NAME} pthread)
