cmake_minimum_required(VERSION 3.6)
project(Entropy)

set(CMAKE_CXX_STANDARD 11)

set (CMAKE_MODULE_PATH "C:\\Users\\Leonardo paroli\\AppData\\Roaming\\JetBrains\\SFML-2.4.2\\cmake\\Modules")
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES main.cpp Game.cpp Game.h SharedContext.h State_Game.cpp State_Game.h State_Intro.h State_Intro.cpp
        intro.png arial.ttf BaseState.cpp BaseState.h EventDetails.h EventManager.cpp EventManager.h Key.cfg
        State_MainMenu.h State_MainMenu.cpp State_Pause.h State_Pause.cpp StateManager.cpp StateManager.h Window.cpp
        Window.h EnumHasher.h StateType.h)
add_executable(Entropy ${SOURCE_FILES})
target_link_libraries(Entropy ${SFML_LIBRARIES})