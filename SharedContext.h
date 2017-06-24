//
// Created by Leonardo on 5/1/2017.
//

#ifndef ENTROPY_SHAREDCONTEXT_H
#define ENTROPY_SHAREDCONTEXT_H

class Window;
class EventManager;

struct SharedContext {
    SharedContext() : m_wind(nullptr), m_eventManager(nullptr) {}
    Window *m_wind;
    EventManager *m_eventManager;
};

#endif //ENTROPY_SHAREDCONTEXT_H
