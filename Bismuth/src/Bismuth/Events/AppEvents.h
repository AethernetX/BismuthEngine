#pragma once

#include "Events.h"

#include <sstream>

namespace bi {
    class BISMUTH_API WindowResizeEvent : public Event {
        private:
            unsigned int m_Width, m_Height;
        
        public:
            WindowResizeEvent(unsigned int width, unsigned int height) :
                m_Width(width), m_Height(height) {}

        inline unsigned int getWidth() const { return m_Width; }
        inline unsigned int getHeight() const { return m_Height; }

        std::string toString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent " << m_Width << " , " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class BISMUTH_API WindowsCloseEvent : public Event {
        public:
        WindowsCloseEvent(){}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class BISMUTH_API AppUpdateEvent : public Event {
        public:
            AppUpdateEvent() {}

            EVENT_CLASS_TYPE(AppUpdate)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class BISMUTH_API AppRenderEvent : public Event {
        public:
            AppRenderEvent() {}

            EVENT_CLASS_TYPE(AppUpdate)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

}