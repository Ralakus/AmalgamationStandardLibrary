#include "../Platform/Typedef.hpp"

#if defined(AE_WINDOWS)
    #include <chrono>
#else
    #include <windows.h>
#endif // AE_Windows

namespace AESL{

    class Timer{

        #if defined(AE_WINDOWS)

        float m_InvFreqMilli;
        bool m_Running;
        unsigned long long m_Now;
        unsigned long long m_Start;
        unsigned long long m_Frequency;

    public:

        Timer() {
            QueryPerformanceFrequency( (LARGE_INTEGER*)&m_Frequency );
            m_InvFreqMilli = 1.0f / (float)((double)m_Frequency / 1000.0);
        }
        ~Timer() {}

        void Start(){
            if(m_Running){
                QueryPerformanceCounter( (LARGE_INTEGER*)&m_Now );
                m_Running = false;
            }
        }
        void Stop() {
            m_Running = true;
            QueryPerformanceCounter( (LARGE_INTEGER*)&m_Start );
        }

        float GetTimeMilli() const {
            if( m_Running )
            {
                QueryPerformanceCounter( (LARGE_INTEGER*)&m_Now );
            }
            return (float)(m_Now - m_Start) * m_InvFreqMilli;
        }
        float GetTimeSec() const {
            return GetTimeMilli() / 1000.0f;
        }

        bool IsRunning() const { return m_Running; }

        #else

        bool m_Running;
        auto Start = std::chrono::high_resolution_clock::now();
        auto End   = std::chrono::high_resolution_clock::now();

        Timer()  {}
        ~Timer() {}

        void Start() {
            m_Running = true;
            Start = std::chrono::high_resolution_clock::now();
        }

        void Stop() {
            if(m_Running){
                End = std::chrono::high_resolution_clock::now();
                m_Running = false;
            }
        }

        float GetTimeMilli() const {
            if( m_Running )
            {
                Stop();
            }
            return std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count();
        }

        float GetTimeSec() const {
            return GetTimeMilli() / 1000.0f;
        }

        bool IsRunning() const { return m_Running; }

        #endif // AE_Windows

    };

}
