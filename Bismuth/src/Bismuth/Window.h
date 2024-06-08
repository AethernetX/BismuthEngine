#pragma once

#include "bich.h"

#include "Bismuth/Core.h"
#include "Bismuth/Events/Events.h"

namespace bi {

    struct WindowProps {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(
            const std::string& title = "Bismuth Engine",
            unsigned int width = 1280,
            unsigned int height = 720) 
            : Title(title), Width(width), Height(height)
        {
        }
    };

    // Interface representing a desktop system based Window
    class BISMUTH_API Window {
        public:
        using EventCallBackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void Update() = 0;

        virtual unsigned int getWidth() const = 0;
        virtual unsigned int getHeight() const = 0;

        // Window attributes
        virtual void setEventCallback(const EventCallBackFn& callback) = 0;
        virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

        static Window* create(const WindowProps& props = WindowProps());
    };

    // I'm assuming imgui has some form of rendering surface?
}