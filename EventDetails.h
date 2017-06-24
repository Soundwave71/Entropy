//
// Created by Leonardo on 5/1/2017.
//

#ifndef ENTROPY_EVENTDETAILS_H
#define ENTROPY_EVENTDETAILS_H


#include <SFML/System.hpp>

struct EventDetails{
    //sets details to default
    explicit EventDetails(const std::string& l_bindName):m_name(l_bindName){
        Clear();
    }

    //Event name
    std::string m_name;

    //Event attributes
    sf::Vector2i m_size;
    sf::Uint32 m_textEntered;
    sf::Vector2i m_mouse;
    int m_mouseWheelDelta;
    int m_keyCode; //Single Keycode

    //resets attributes
    void Clear(){
        m_size= sf::Vector2i(0,0);
        m_textEntered = 0;
        m_mouse= sf::Vector2i(0,0);
        m_mouseWheelDelta = 0;
        m_keyCode=-1;
    }
};
#endif //ENTROPY_EVENTDETAILS_H
