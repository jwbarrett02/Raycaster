cmake_minimum_required(VERSION 4.0.1)

project(Raycaster VERSION 1.0.0)

# glad =========================================================
set(GLAD_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/deps/glad/include")
set(GLAD_SRC         "${CMAKE_SOURCE_DIR}/deps/glad/src/glad.c")

add_library(glad STATIC ${GLAD_SRC})
target_include_directories(glad PUBLIC ${GLAD_INCLUDE_DIR})

# OpenGL =======================================================
find_package(OpenGL REQUIRED)

# SDL3 =========================================================
add_definitions(-DSDL_STATIC)

set(SDL3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/deps/SDL3/include")
set(SDL3_LIB_DIR     "${CMAKE_SOURCE_DIR}/deps/SDL3/lib")

link_directories(${SDL3_LIB_DIR})

set(SDL3_LIBS SDL3)

# src files ====================================================
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE 
${CMAKE_SOURCE_DIR}/src
${SDL3_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    glad
    OpenGL::GL
    ${SDL3_LIBS}
)