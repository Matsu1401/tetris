# заимсовование кода
cmake_minimum_required(VERSION 3.27)
project(raylib_cpp_example)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.0
        GIT_SHALLOW 1
    )
    FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    if (NOT DEFINED RAYLIB_CPP_VERSION)
        set(RAYLIB_CPP_VERSION v5.0.1)
    endif()
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG ${RAYLIB_CPP_VERSION}
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()
# заимсовование кода
set(SOURCES main.cpp)
add_executable(tetris src/main.cpp src/bloki.cpp src/colors.cpp src/Game.cpp src/Mnogoblok.cpp src/posicii.cpp src/setka.cpp )
set_target_properties(tetris PROPERTIES CXX_STANDARD 11)
target_link_libraries(tetris PUBLIC raylib raylib_cpp)


add_executable(testingg src/test_tetris.cpp)
set_target_properties(testingg PROPERTIES CXX_STANDARD 11)
target_link_libraries(testingg PUBLIC raylib raylib_cpp)
enable_testing()
add_test(NAME testingg COMMAND testingg --force-colors -d)


