cmake_minimum_required(VERSION 3.6)
project(Entropy)

set(CMAKE_CXX_STANDARD 11)

set (CMAKE_MODULE_PATH "C:\\Users\\Leonardo paroli\\AppData\\Roaming\\JetBrains\\SFML-2.4.2\\cmake\\Modules")
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES main.cpp BaseState.h EventManager.h EventManager.cpp Game.h Game.cpp Mushroom.png
        arial.ttf intro.png keys.cfg StateManager.h StateManager.cpp SharedContext.h State_Game.h State_Game.cpp
        State_Intro.h State_Intro.cpp State_MainMenu.h State_MainMenu.cpp State_Paused.cpp State_Paused.h Window.h
        Window.cpp EnumHasher.h)
add_executable(Entropy ${SOURCE_FILES})
target_link_libraries(Entropy ${SFML_LIBRARIES})