//
// Created by Leonardo on 4/29/2017.
//

#ifndef ENTROPY_STATE_MAINMENU_H
#define ENTROPY_STATE_MAINMENU_H

#include "BaseState.h"
#include <SFML/Graphics.hpp>
#include "EventDetails.h"

class State_MainMenu: public BaseState {
public:
    explicit State_MainMenu(StateManager* l_stateManager): BaseState(l_stateManager){OnCreate();}
    virtual~State_MainMenu(){OnDestroy();}

    virtual void OnCreate ()override;
    virtual void OnDestroy()override;
    virtual void Activate()override;
    virtual void Deactivate()override;
    virtual void Update (const sf::Time& l_time)override;
    virtual void Draw()override;

    //Mouse Event Function
    void MouseClick(EventDetails* l_details);

private:
    sf::Font m_font;
    sf::Text m_text;
    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    unsigned int m_buttonPadding;

    sf::RectangleShape m_rects[3];
    sf::Text m_labels[3];
};


#endif //ENTROPY_STATE_MAINMENU_H
