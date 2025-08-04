cmake_minimum_required(VERSION 3.31.6)

project(DinoRunCopy
VERSION 0.1.0
LANGUAGES CXX)

#global project settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#fetch sfml

include(FetchContent)




#project variable
set(GAME_EXE "Dinorun_Copy")


add_executable(${GAME_EXE} "src/main.cpp")
target_include_directories(${GAME_EXE} PRIVATE "include")
target_precompile_headers(${GAME_EXE} PRIVATE "include/PCH.hpp")

add_subdirectory(src)