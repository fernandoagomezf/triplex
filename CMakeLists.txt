cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(Triplex)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-windows")
 
add_executable(Triplex
    src/application.cpp
    src/game.cpp
    src/invalid_level.cpp 
    src/program.cpp 
    src/safe_box.cpp
)

target_include_directories(Triplex PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include  
)