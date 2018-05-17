#pragma once

#include "../Types/Noncopyable.hpp"

namespace AESL{

    class IEventCallback : public Noncopyable {
    public:

        IEventCallback() : Noncopyable() {};
        virtual ~IEventCallback() {}

        virtual void operator()() = 0;
        virtual bool operator == (IEventCallback* Other) = 0;
    };

    template<class T>
    class EventCallback : public IEventCallback {

        T* m_Instance;
        void (T::*m_Function)();

    public:

        EventCallback(T* Instance, void (T::*Function)()) : IEventCallback(), m_Instance(Instance), m_Function(Function) {}
        ~EventCallback (){}

        virtual void operator()() override { (m_Instance->*m_Function)(); };

        virtual bool operator == (IEventCallback* Other) override {
            EventCallback<T>* OtherEC = dynamic_cast<EventCallback<T>*>(Other);
            if(OtherEC == nullptr){
                return false;
            }
            return  (this->m_Function == OtherEC->m_Function) &&
                    (this->m_Instance == OtherEC->m_Instance);
        }

    };


    class EventFunctionCallback : public IEventCallback {

        void (*m_Function)();

    public:

        EventFunctionCallback(void (*Function)()) : IEventCallback(), m_Function(Function) {}
        ~EventFunctionCallback (){}

        virtual void operator()() override { (*m_Function)(); };

        virtual bool operator == (IEventCallback* Other) override {
            EventFunctionCallback* OtherEC = dynamic_cast<EventFunctionCallback*>(Other);
            if(OtherEC == nullptr){
                return false;
            }
            return  (this->m_Function == OtherEC->m_Function);
        }

    };

}
