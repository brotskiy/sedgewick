PROJECT (sedgewick_tasks CXX)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(BINDIR ${sedgewick_tasks_SOURCE_DIR}/bin)
SET(LIBDIR ${sedgewick_tasks_SOURCE_DIR}/lib)

SET(EXECUTABLE_OUTPUT_PATH ${BINDIR})
SET(LIBRARY_OUTPUT_PATH ${LIBDIR})

file(GLOB_RECURSE src_list src/*.cpp src/*.cpp)
add_executable(${PROJECT_NAME} ${src_list})
target_link_libraries(
    ${PROJECT_NAME})
