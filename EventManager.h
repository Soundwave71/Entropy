//
// Created by Leonardo on 4/23/2017.
//

#ifndef ENTROPY_EVENTMANAGER_H
#define ENTROPY_EVENTMANAGER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include "EventDetails.h"
#include "EnumHasher.h"

enum class EventType{
    KeyDown=sf::Event::KeyPressed,
    KeyUp=sf::Event::KeyReleased,
    MButtonDown=sf::Event::MouseButtonPressed,
    MButtonUp=sf::Event::MouseButtonReleased,
    MouseWheel=sf::Event::MouseWheelMoved,
    WindowResized=sf::Event::Resized,
    GainedFocus=sf::Event::GainedFocus,
    LostFocus=sf::Event::LostFocus,
    MouseEntered=sf::Event::MouseEntered,
    MouseLeft=sf::Event::MouseLeft,
    Closed=sf::Event::Closed,
    TextEntered=sf::Event::TextEntered,
    Keyboard =sf::Event::Count +1, Mouse
};

//Event- info container
struct EventInfo{

    // stores event with no type with default m_code=0
    EventInfo(){m_code= 0;}

    //stores integer of the event type.
    explicit EventInfo( int l_event){m_code=l_event;}

    //TODO search union's definition.
    union{
        int m_code;
    };
};

//Events is a vector of the type and the code of the event.
using Events =std::vector<std::pair<EventType, EventInfo>>;


struct Binding{
    //sets class members
    explicit Binding(const std::string& l_name): m_name (l_name), m_details(l_name), c(0){};

    //binds  type and info of the event to Events vector.
    void BindEvent(EventType l_type, EventInfo l_info=EventInfo()){
      m_events.emplace_back(l_type, l_info);
    }
    Events m_events;
    std::string m_name;
    int c; //Counts of "happening" events
    EventDetails m_details;
};

//TODO ask about unordered_map errors.
using Bindings = std::unordered_map <std::string, Binding*>;

enum class StateType;

//TODO ask about std::function and std::bind and callbacks in general.
using CallbackContainer =std::unordered_map <std::string, std::function<void(EventDetails*)>>;
using Callbacks = std::unordered_map <StateType , CallbackContainer, EnumClassHash>;


class EventManager {
public:
    EventManager();
    ~EventManager();

    bool AddBinding(Binding *l_binding);
    bool RemoveBinding(std::string l_name);
    void SetFocus(const bool& l_focus);

    template<class T>
    bool AddCallback(StateType l_state, const std::string& l_name, void (T::*l_func)(EventDetails*), T*l_instance)
    {
        auto itr =m_callbacks.emplace(l_state, CallbackContainer()).first;
        auto temp= std::bind (l_func, l_instance, std::placeholders::_1);
        return  itr->second.emplace(l_name, temp).second;
    }

    bool RemoveCallback (StateType l_state, const std::string& l_name)
    {
        auto itr = m_callbacks.find(l_state);
        if(itr == m_callbacks.end()) {return false;}
        auto itr2 = itr->second.find(l_name);
        if(itr2 == itr->second.end()){return false;}
        itr->second.erase(l_name);
        return true;
    }

    void HandleEvent (sf::Event& l_event);

    void Update();

    void SetCurrentState(StateType l_type){
        m_currentState= l_type;
    }

    //returns position of the mouse relative to window (if passed) or the absolute mouse position.
    sf::Vector2i GetMousePos(sf::RenderWindow* l_wind= nullptr){
        return (l_wind? sf::Mouse::getPosition(*l_wind): sf::Mouse::getPosition());
    }
private:
    void LoadBindings();

    // string to int
    int StringToInt(std::string key);

    //Binding vector
    Bindings m_bindings;

    //Callbacks vector
    Callbacks m_callbacks;

    bool m_hasFocus;

    StateType m_currentState;

};


#endif //ENTROPY_EVENTMANAGER_H
