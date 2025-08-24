cmake_minimum_required(VERSION 3.15)
project(simTest VERSION 1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
find_package(SDL3 REQUIRED CONFIG)
add_executable(simTest src/main.cpp
        Includes/Utils.h
        Includes/Colors.h
        src/Simulator_gui.cpp
        Includes/Simulator_gui.h
        src/simulator_core.cpp
        Includes/simulator_core.h
        src/ball.cpp
        Includes/ball.h)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
target_compile_definitions(${PROJECT_NAME} PRIVATE SDL_MAIN_USE_CALLBACKS)
