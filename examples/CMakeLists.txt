cmake_minimum_required(VERSION 2.8)

include_directories(${ENGINE_INCLUDE_DIR})
link_directories(${ENGINE_LIBRARY_DIR})
link_libraries(${ENGINE_LIBRARY})

add_executable(example
    main.cpp
)
