#pragma once

namespace bi {

    class Application
    {
    public:
        Application(/* args */);
        virtual ~Application();
    
        void run();
    };

    // to be defined by the client
    Application* CreateApplication();
    
}