//
// Created by Leonardo on 4/23/2017.
//


#ifndef ENTROPY_GAME_H
#define ENTROPY_GAME_H

#include "Window.h"
#include "StateManager.h"

class Game {
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();

    sf::Time GetElapsed();
    void RestartClock();

    void LateUpdate();
private:
    SharedContext m_context;
    Window m_window;
    sf::Clock m_clock;
    sf::Time m_elapsed;
    StateManager m_stateManager;
};


#endif //ENTROPY_GAME_H
