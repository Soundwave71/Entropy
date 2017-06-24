//
// Created by Leonardo on 4/30/2017.
//

#ifndef ENTROPY_STATE_GAME_H
#define ENTROPY_STATE_GAME_H


#include <SFML/Graphics.hpp>
#include "BaseState.h"
#include "EventManager.h"


class State_Game: public BaseState {
public:
    explicit State_Game(StateManager* l_stateManager):BaseState{l_stateManager}{OnCreate();}
    virtual ~State_Game(){OnDestroy();}

    virtual void OnCreate () override;
    virtual void OnDestroy() override;
    virtual void Activate() override;
    virtual void Deactivate()override;
    virtual void Update (const sf::Time& l_time) override;
    virtual void Draw() override;

    //State switching functions
    void MainMenu (EventDetails* l_details);
    void Pause (EventDetails* l_details);

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_increment;
};


#endif //ENTROPY_STATE_GAME_H
