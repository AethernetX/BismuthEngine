#pragma once

#include "bich.h"

#include "Bismuth/Core.h"

namespace bi {

    /*Currently the events are blocking, which means when an event occurs
    it will immediately get dispatched and must be dealt with right then and there
    
    It is prefereble to buffer the events in an event bus and process them during
    the event part of the update stage*/

    //It would be preferrable for a getInputDown event

    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCatagory {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput       = BIT(0),
        EventCategoryKeyboard    = BIT(0),
        EventCategoryMouse       = BIT(0),
        EventCategoryMouseButton = BIT(0),
    };

    #define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::type; }\
                                   virtual EventType getEventType() const override { return getStaticType(); }\
                                   virtual const char* getName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

    class BISMUTH_API Event {
            friend class EventDispatcher;
        public:
            virtual EventType getEventType() const = 0;
            virtual const char* getName() const = 0;
            virtual int getCategoryFlags() const = 0;
            virtual std::string toString() const { return getName(); }

            inline bool isInCategory(EventCatagory category){
                return getCategoryFlags() & category;
            }

        protected:
            bool m_Handled = false;
    };

    //if it doesn't work, see if removing the bismuth api macro here works
    class BISMUTH_API EventDispatcher{
            template<typename T>
            using EventFn = std::function<bool(T&)>;
        public:
            EventDispatcher(Event& event) : m_Event(event) {
            }
        
            template<typename T>
            bool dispatch(EventFn<T> func){
                if(m_Event.getEventType() == T::getStaticType()){
                    m_Event.m_Handled = func(*(T*)&m_Event);
                    return true;
                }
                return false;
            }
        private:
            Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e){
        return os<< e.toString();
    }

}