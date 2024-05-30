#include "Application.h"

#include "Events/AppEvents.h"
#include "Log.h"

namespace bi {
     
    Application::Application(/* args */)
    {
    }
    
    Application::~Application()
    {
    }
    
    void Application::run(){
        WindowResizeEvent e(1280, 720);
        /*
        I'm pretty unsure why BI_TRACE(e) doesn't just work out the box
        See https://github.com/gabime/spdlog/issues/1227 for more info
        */
		if (e.isInCategory(EventCategoryApplication))
		{
			BI_TRACE(e.toString());
		}
		if (e.isInCategory(EventCategoryInput))
		{
			BI_TRACE(e.toString());
		}

        while(true);
    }
}