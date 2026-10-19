cmake_minimum_required(VERSION 3.28)
project(CafeMoi VERSION 0.1.0 LANGUAGES CXX)

# CMAKE_CURRENT_LIST_DIR is the directory holding the CMakeLists.txt we are currently using
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} src/main.cpp
        src/CafeMoi.cpp
        src/CafeMoi.h)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics ${PHRO_LIBRARY})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)

# CafeMoi-tests

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.8.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

add_executable(${PROJECT_NAME}-tests tests/test_main.cpp
        src/CafeMoi.cpp
        src/CafeMoi.h)
target_link_libraries(${PROJECT_NAME}-tests PRIVATE Catch2::Catch2WithMain)