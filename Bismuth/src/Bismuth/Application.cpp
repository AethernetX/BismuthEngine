#include "bich.h"
#include "Application.h"

//#include <vulkan/vulkan.h>

namespace bi {
     
#define BIND_EVENT_FN(x) std::bind(x, this, std::placeholders::_1)

    Application::Application(/* args */)
    {
        m_Window = std::unique_ptr<Window>(Window::create());
        m_Window->setEventCallback(BIND_EVENT_FN(&Application::OnEvent));
    }
    
    Application::~Application()
    {
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowsCloseEvent>(BIND_EVENT_FN(&Application::onWindowCloseEvent));

        //WARN spdlog ostr doesn't work for some reason
        BI_CORE_TRACE("{0}", e.toString());

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->onEvent(e);
            if (e.handled)
                break;
        }
    }

    void Application::pushLayer(Layer* layer)
    {
        m_LayerStack.pushLayer(layer);
    }

    void Application::pushOverlay(Layer* layer)
    {
        m_LayerStack.pushOverlay(layer);
    }
    
    bool Application::onWindowCloseEvent(WindowsCloseEvent& event) {
        m_Running = false;
        return true;
    }

    void Application::run(){
        while(m_Running){
            //todo: use vulkan's version of setting a background colour
            m_Window->Update();
        }
    }
}