cmake_minimum_required(VERSION 3.10)
project(cosyne LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 11)
find_package(Boost REQUIRED COMPONENTS program_options)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(cosyne
    src/main.cpp
    src/network.cpp
    )
target_link_libraries(cosyne ${Boost_LIBRARIES})
