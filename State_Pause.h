//
// Created by Leonardo on 4/30/2017.
//

#ifndef ENTROPY_STATE_PAUSED_H
#define ENTROPY_STATE_PAUSED_H

#include <SFML/Graphics.hpp>
#include "BaseState.h"
#include "EventDetails.h"

class State_Pause : public BaseState{
public:
    explicit State_Pause(StateManager* l_stateManager): BaseState(l_stateManager){OnCreate();}
    virtual ~State_Pause(){OnDestroy();}

    virtual void OnCreate ()override;
    virtual void OnDestroy()override;
    virtual void Activate()override;
    virtual void Deactivate()override;
    virtual void Update (const sf::Time& l_time)override;
    virtual void Draw()override;

    void Unpause(EventDetails* l_details);
private:
    sf::Font m_font;
    sf::Text m_text;
    sf::RectangleShape m_rect;
};


#endif //ENTROPY_STATE_PAUSED_H
