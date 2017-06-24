//
// Created by Leonardo paroli on 26/04/2017.
//


#include "StateManager.h"
//Registers state to manage.
StateManager::StateManager(SharedContext* l_shared): m_shared(l_shared) {
    RegisterState<State_Intro>(StateType::Intro);
    RegisterState<State_MainMenu>(StateType::MainMenu);
    RegisterState<State_Game>(StateType::Game);
    RegisterState<State_Pause>(StateType::Credits);
}

StateManager::~StateManager() {
    for( auto &itr: m_states)
    {
        itr.second->OnDestroy();
        delete itr.second;
    }
}

void StateManager::Draw() {
    if(m_states.empty()){return;}
    if(m_states.back().second->IsTransparent()&& m_states.size() >1)
    {
        auto itr= m_states.end();
        while (itr!= m_states.begin())
        {
            if(itr != m_states.end())
            {
                if(!itr->second->IsTransparent())
                {
                    break;
                }
            }
            --itr;
        }
        for(; itr!= m_states.end(); ++itr)
        {
            itr->second->Draw();
        }
    }else{
        m_states.back().second->Draw();
    }
}

//updates all states based on transcendence flag.
void StateManager::Update(const sf::Time l_time) {
    //if there are no states, do nothing.
    if (m_states.empty()){return;}

    //Checks if top state allows other to update
    if(m_states.back().second->IsTranscendent()&& m_states.size()>1)
    {
        auto itr = m_states.end();

        //iterates on
        while(itr!=m_states.begin())
        {
            if(itr !=m_states.end())
            {
                //checks if current State allows the subsequent states to update
                if(!itr->second->IsTranscendent()){ break; }
            }
            --itr;
        }
        //updates all states with DELTA TIME.
        for(;itr!=m_states.end(); ++itr){
            itr->second->Update(l_time);
        }
    }else {
        m_states.back().second->Update(l_time);
    }
}

//returns current context
SharedContext *StateManager::GetContext() { return m_shared; }

//checks if a State is on the Stack.
bool StateManager::HasState(const StateType &l_type) {
    for(auto itr = m_states.begin(); itr!= m_states.end(); ++itr)
    {
        if( itr->first == l_type)
        {
         auto removed = std::find(m_toRemove.begin(),m_toRemove.end(), l_type);
            if(removed == m_toRemove.end()){return true;}
            return false;
        }
    }
    return false;
}

void StateManager::SwitchTo(const StateType &l_type) {
    m_shared->m_eventManager->SetCurrentState(l_type);
    for(auto itr= m_states.begin(); itr != m_states.end(); ++itr)
    {
        if(itr->first == l_type)
        {
            m_states.back().second->Deactivate();
            StateType  tmp_type =itr->first;
            BaseState* tmp_state= itr->second;
            m_states.erase(itr);
            m_states.emplace_back(tmp_type, tmp_state);
            tmp_state->Activate();
            return;
        }
    }

    //State with l_type wasn't found.
    if(!m_states.empty()){m_states.back().second->Deactivate();}
    CreateState(l_type);
    m_states.back().second->Activate();
}

void StateManager::Remove(const StateType &l_type) {
    m_toRemove.push_back(l_type);
}

void StateManager::CreateState(const StateType &l_type) {
    auto newState = m_stateFactory.find(l_type);
    if(newState == m_stateFactory.end()){return;}
    BaseState* state = newState->second();
    m_states.emplace_back( l_type, state);
    state->OnCreate();
}

void StateManager::RemoveState(const StateType &l_type) {
    for(auto itr = m_states.begin(); itr != m_states.end(); ++itr)
    {
        if(itr->first == l_type)
        {
            itr->second->OnDestroy();
            delete itr->second;
            m_states.erase(itr);
            return;
        }
    }
}

//iterates over m_toRemove vector
void StateManager::ProcessRequests() {
    while(m_toRemove.begin() != m_toRemove.end())
    {
        RemoveState(*m_toRemove.begin());
        m_toRemove.erase(m_toRemove.begin());
    }
}






