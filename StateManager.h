//
// Created by Leonardo paroli on 26/04/2017.
//

#ifndef ENTROPY_STATEMANAGER_H
#define ENTROPY_STATEMANAGER_H


class Game;
#include <functional>
#include <unordered_map>
#include "State_Intro.h"
#include "State_MainMenu.h"
#include "State_Game.h"
#include "State_Pause.h"
#include "SharedContext.h"
#include "EventManager.h"
#include "EnumHasher.h"
#include "StateType.h"


using StateContainer = std::vector<std::pair<StateType,  BaseState*>>;
using TypeContainer = std::vector<StateType>;
using StateFactory = std::unordered_map<StateType, std::function<BaseState* (void)>, EnumClassHash>;

class StateManager {
public:
    explicit StateManager(SharedContext* l_shared);
    ~StateManager();

    void Update(const sf::Time l_time);
    void Draw();

    void ProcessRequests();

    SharedContext* GetContext();
    bool HasState(const StateType& l_type);

    void SwitchTo(const StateType& l_type);
    void Remove (const StateType& l_type);

private:
    //methods
    void CreateState(const StateType& l_type);
    void RemoveState(const StateType& l_type);

    template<class T>
    void RegisterState(const StateType& l_type)
    {
        m_stateFactory[l_type] = [this]()-> BaseState*{
            return new T (this);
        };
    }

    //Members
    SharedContext* m_shared;
    StateContainer m_states;
    TypeContainer  m_toRemove;
    StateFactory  m_stateFactory;

};

#endif //ENTROPY_STATEMANAGER_H
