#pragma once

#include "Core.h"

namespace bi {

    class BISMUTH_API Application
    {
    public:
        Application(/* args */);
        virtual ~Application();
    
        void run();
    };

    // to be defined by the client
    Application* CreateApplication();
    
}