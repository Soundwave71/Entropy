//
// Created by Leonardo on 4/29/2017.
//

#ifndef ENTROPY_STATE_INTRO_H
#define ENTROPY_STATE_INTRO_H

#include <SFML/Graphics.hpp>
#include "EventDetails.h"
#include "BaseState.h"

class State_Intro: public BaseState {

public:
    explicit State_Intro(StateManager* l_stateManager):BaseState(l_stateManager){OnCreate();}
    virtual~State_Intro(){OnDestroy();}

    virtual void OnCreate() override;
    virtual void OnDestroy() override;
    virtual void Update(const sf::Time& l_time) override;
    virtual void Draw() override;
    virtual void Activate ()override;
    virtual void Deactivate()override;

    void Continue (EventDetails * l_details);
private:
    sf::Font m_font;
    sf::Texture m_introTexture;
    sf::Sprite  m_introSprite;
    sf::Text m_text;
    float m_timePassed;
};

#endif //ENTROPY_STATE_INTRO_H
