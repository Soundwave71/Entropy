//
// Created by Leonardo on 4/30/2017.
//

#include "State_Pause.h"
#include "StateManager.h"
#include "Window.h"

void State_Pause::OnCreate() {
    SetTransparent(true);
    m_font.loadFromFile("arial.ttf");
    m_text.setFont(m_font);
    m_text.setString("PAUSED");
    m_text.setCharacterSize(14);
    m_text.setStyle(sf::Text::Bold);

    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();
    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top + textRect.height/2.0f);
    m_text.setPosition(windowSize.x/2.0f, windowSize.y/2.0f);

    m_rect.setSize(sf::Vector2f(windowSize));
    m_rect.setPosition(0,0);
    m_rect.setFillColor(sf::Color(0,0,0,150));
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Paused, "Key_P", &State_Pause::Unpause, this);

}

void State_Pause::OnDestroy() {
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Paused, "Key_P");
}

void State_Pause::Draw() {
    sf::RenderWindow* wind = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    wind->draw(m_rect);
    wind->draw(m_text);
}

void State_Pause::Unpause(EventDetails *l_details) {
    m_stateMgr->SwitchTo(StateType::Game);
}

void State_Pause::Activate() {}

void State_Pause::Deactivate() {}

void State_Pause::Update(const sf::Time &l_time) {}




