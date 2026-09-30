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

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/AssetsManager.cpp
        src/Logger.cpp
        src/Tileset.cpp
        src/pugixml.cpp
        src/Tilemap.cpp
        src/CSV.cpp
        src/Camera.cpp
        src/Building.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)

file(GLOB_RECURSE RESOURCE_FILES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/resources/*"
)

add_custom_target(update_resources
        COMMAND ${CMAKE_COMMAND} -E remove_directory
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/resources"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources"
        DEPENDS ${RESOURCE_FILES}
        COMMENT "Updating resources..."
)

add_dependencies(${PROJECT_NAME} update_resources)
