cmake_minimum_required(VERSION 2.8)

project(luigui)

include(CTest)

# Set options
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the build type ( Debug / Release )" FORCE)
endif()
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

# Enable C++14
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules;${CMAKE_MODULE_PATH}")

# Add source files
set(SRC_DIR "src")
set(INC_DIR "inc")

include_directories(${SRC_DIR})
include_directories(${INC_DIR})

set( SOURCES
    ${INC_DIR}/entity.hpp
    ${SRC_DIR}/entity.cpp
    ${INC_DIR}/button.hpp
)

find_package(OpenGL)
include_directories(${OPENGL_INCLUDE_DIRS})
link_libraries(${OPENGL_LIBRARIES})

add_library(${CMAKE_PROJECT_NAME} ${SOURCES})

set(ENGINE_LIBRARY ${CMAKE_PROJECT_NAME})
set(ENGINE_LIBRARY_DIR ${CMAKE_SOURCE_DIR})
set(ENGINE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/${INC_DIR})

# install(TARGETS ${CMAKE_PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_SOURCE_DIR}/docs/Doxyfile.in ${CMAKE_BINARY_DIR}/docs/Doxyfile @ONLY)
    add_custom_command(OUTPUT documentation COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/docs/Doxyfile BYPRODUCTS ${CMAKE_BINARY_DIR}/docs/html ${CMAKE_BINARY_DIR}/docs/Doxyfile COMMENT "Generating docs using Doxygen" VERBATIM)
    add_custom_target(docs ALL DEPENDS documentation VERBATIM)
    set_directory_properties(PROPERTY ADDITIONAL_MAKE_CLEAN_FILES ${CMAKE_BINARY_DIR}/docs)
endif()

find_package(Vera++)
if(VERA_FOUND)
    file(GLOB_RECURSE VERA_SOURCES RELATIVE ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/*.hpp
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/inc/*.hpp
        ${CMAKE_SOURCE_DIR}/inc/*.cpp
        ${CMAKE_SOURCE_DIR}/examples/*.hpp
        ${CMAKE_SOURCE_DIR}/examples/*.cpp
    )
    add_custom_command(
        OUTPUT vera_style_cmd
        COMMAND ${VERA_EXECUTABLE} --warning ${VERA_SOURCES} -r ${CMAKE_SOURCE_DIR}/style -p main
        COMMENT "Checking code style with Vera++."
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        VERBATIM
    )
    add_custom_target(vera_style ALL DEPENDS vera_style_cmd VERBATIM)

    enable_testing()
    add_test(
        NAME code_style 
        COMMAND ${VERA_EXECUTABLE} --error ${VERA_SOURCES} -r ${CMAKE_SOURCE_DIR}/style -p main
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
endif()

# install(DIRECTORY resources DESTINATION ${CMAKE_SOURCE_DIR}/bin/)

add_subdirectory(examples)
