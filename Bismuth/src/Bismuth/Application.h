#pragma once

#include "Core.h"
#include "Events/Events.h"
#include "Window.h"

#include "Bismuth/Events/AppEvents.h"

namespace bi {

    class BISMUTH_API Application
    {
    public:
        Application(/* args */);
        virtual ~Application();
    
        void run();

        void OnEvent(Event& e);
    private:
        bool onWindowCloseEvent(WindowsCloseEvent& event);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // to be defined by the client
    Application* CreateApplication();
    
}