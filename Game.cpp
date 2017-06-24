//
// Created by Leonardo on 4/23/2017.
//

#include "Game.h"
//sets SharedContext fields and starts State_Domino_Effect
Game::Game(): m_window("Entropy", sf::Vector2u(800,600)), m_stateManager(&m_context) {
    {
        m_context.m_wind=&m_window;
        m_context.m_eventManager=m_window.GetEventManager();
        m_stateManager.SwitchTo(StateType::Intro);
    }
}

Game::~Game() {

}

void Game::HandleInput() {
//TODO handling input
}

void Game::Update() {
    m_window.Update();
    m_stateManager.Update(m_elapsed);
}

void Game::Render() {
    m_window.BeginDraw();
    m_stateManager.Draw();
    m_window.EndDraw();
}

void Game::LateUpdate() {
    m_stateManager.ProcessRequests();
    RestartClock();
}

sf::Time Game::GetElapsed() {
    return m_elapsed;
}

void Game::RestartClock() {
    m_elapsed = m_clock.restart();
}

Window *Game::GetWindow() {
    return &m_window;
}






