#pragma once

#include "Event.hpp"
#include "../Platform/Typedef.hpp"
#include <string>
#include <unordered_map>

namespace AESL{
    class EventHandler {

        std::unordered_map<std::string, Event*> m_Events;

    public:

        EventHandler() {}
        virtual ~EventHandler() {}

        virtual void RegisterCallback(const std::string& Name, IEventCallback* Callback) {
            if(m_Events.count(Name) < 1){
                return;
            }
            else{
                m_Events[Name]->AddListener(Callback);
            }
        }
        virtual void RegisterEvent(const std::string& Name, Event* Event){
            if(m_Events.count(Name) < 1){
                m_Events[Name] = Event;
            }
        }
        virtual void TriggerEvent(const std::string& Name){
            if(m_Events.count(Name) > 0){
                m_Events[Name]->Trigger();
            }
        }
    };
}
