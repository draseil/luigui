cmake_minimum_required(VERSION 2.8)

find_package(GLEW)

include_directories(${GLEW_INCLUDE_DIR})
link_libraries(${GLEW_LIBRARY})
link_libraries(glfw)

include_directories(${ENGINE_INCLUDE_DIR})
link_directories(${ENGINE_LIBRARY_DIR})
link_libraries(${ENGINE_LIBRARY})

add_executable(example
    main.cpp
)
