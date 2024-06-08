#include "bich.h"
#include "Application.h"

#include "Bismuth/Events/AppEvents.h"

#include <GLFW/glfw3.h>

namespace bi {
     
    Application::Application(/* args */)
    {
        m_Window = std::unique_ptr<Window>(Window::create());
    }
    
    Application::~Application()
    {
    }
    
    void Application::run(){
        while(m_Running){
            //todo: use vulkan's version of setting a background colour
            m_Window->Update();
        }
    }
}