#pragma once

namespace bi {

    class Application
    {
    private:
        /* data */
    public:
        Application(/* args */);
        virtual ~Application();
    
        void run();
    };

    // to be defined by the client
    Application* CreateApplication();
    
}