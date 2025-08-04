cmake_minimum_required(VERSION 3.31.6)

project(DinoRunCopy
VERSION 0.1.0
LANGUAGES CXX)

#global project settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#fetch sfml

include(FetchContent)

FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG 3.0.1
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(SFML)


#project variable
set(GAME_EXE "Dinorun_Copy")


add_executable(${GAME_EXE} "src/main.cpp")
target_include_directories(${GAME_EXE} PRIVATE "include")
target_precompile_headers(${GAME_EXE} PRIVATE "include/PCH.hpp")
target_link_libraries(${GAME_EXE} PRIVATE sfml-system sfml-graphics sfml-window sfml-audio)

add_subdirectory(src)