//
// Created by Leonardo on 4/23/2017.
//

#ifndef ENTROPY_WINDOW_H
#define ENTROPY_WINDOW_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "EventManager.h"

class Window {
public:

    //Window-related functions
    Window ();
    Window(const std::string& l_title, const sf::Vector2u l_size);
    ~Window();

    //Clear-Display functions
    void BeginDraw();
    void EndDraw();

    //Updates window's attributes
    void Update();

    //Getter functions
    bool is_Done();
    bool is_Fullscreen();
    sf::Vector2u GetWindowSize();
    sf::RenderWindow* GetRenderWindow() { return &m_window; }

    void Draw(sf::Drawable& l_drawable);

    //EventManager-related functions
    bool isFocused();
    EventManager* GetEventManager();


    void ToggleFullscreen (EventDetails* l_details);
    void Close(EventDetails* l_details =nullptr);

private:
    void Setup(const std::string& l_title, const sf::Vector2u& l_size);
    void Destroy();
    void Create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullscreen;

    EventManager m_eventManager;
    bool m_isFocused;
};


#endif //ENTROPY_WINDOW_H
