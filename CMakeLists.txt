cmake_minimum_required(VERSION 3.15)

project(MyRaylibGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory(src SRC_FILES)

find_package(raylib CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED) # Explicitly find glfw3 as it's a direct dependency for linking

add_executable(${PROJECT_NAME} ${SRC_FILES})

if (DEFINED VCPKG_INSTALLED_DIR AND DEFINED VCPKG_TARGET_TRIPLET)
    message(STATUS "VCPKG_INSTALLED_DIR: ${VCPKG_INSTALLED_DIR}")
    message(STATUS "VCPKG_TARGET_TRIPLET: ${VCPKG_TARGET_TRIPLET}")

    target_link_directories(${PROJECT_NAME} PRIVATE "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/lib")
    target_link_directories(${PROJECT_NAME} PRIVATE "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/debug/lib")
else()
    message(WARNING "VCPKG_INSTALLED_DIR or VCPKG_TARGET_TRIPLET is not defined. Linker might not find vcpkg libraries.")
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    raylib
    glfw3
)

if (APPLE)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(COREVIDEO_LIBRARY CoreVideo REQUIRED) # Often needed for display synchronization
    find_library(COREGRAPHICS_LIBRARY CoreGraphics REQUIRED) # For graphics contexts
    find_library(APPKIT_LIBRARY AppKit REQUIRED) # For GUI applications

    target_link_libraries(${PROJECT_NAME} PRIVATE
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
        ${COREVIDEO_LIBRARY}
        ${COREGRAPHICS_LIBRARY}
        ${APPKIT_LIBRARY}
    )
endif()