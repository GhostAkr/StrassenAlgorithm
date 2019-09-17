cmake_minimum_required(VERSION 3.0.0)
project(StrassenAlgorithm VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(StrassenAlgorithm project/src/main.cpp project/include/StrassenAlgorithm.h project/src/StrassenAlgorithm.cpp)

target_include_directories(StrassenAlgorithm PRIVATE project/include)

set(EXECUTABLE_OUTPUT_PATH "")

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "a")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
