cmake_minimum_required(VERSION 3.14)
project(Particles)
# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)
set(COMPILE_OPTIONS "-Wall")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules )
add_executable(particle)

add_subdirectory(src)
target_compile_options(particle PRIVATE ${COMPILE_OPTIONS})
target_link_libraries(particle PRIVATE "-lpthread")
include("./include/add_include_path.cmake")

find_package(Sfml REQUIRED)

if(EnableTests)
    include ("./tests/gtests.cmake")

endif()
