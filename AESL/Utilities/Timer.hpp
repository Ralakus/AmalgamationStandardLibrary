#include "../Platform/Typedef.hpp"

#if defined(AE_WINDOWS)
    #include <windows.h>
#else
    #include <chrono>
#endif // AE_Windows

namespace AESL{

    class Timer{

        bool m_Running;

        #if defined(AE_WINDOWS)
            float m_InvFreqMilli;
            unsigned long long m_Now;
            unsigned long long m_Start;
            unsigned long long m_Frequency;
        #else
            std::chrono::high_resolution_clock::time_point Start = std::chrono::high_resolution_clock::now();
            std::chrono::high_resolution_clock::time_point End   = std::chrono::high_resolution_clock::now();
        #endif

    public:

        Timer()  {
            #if defined(AE_WINDOWS)
                QueryPerformanceFrequency( (LARGE_INTEGER*)&m_Frequency );
                m_InvFreqMilli = 1.0f / (float)((double)m_Frequency / 1000.0);
            #endif
        }
        ~Timer() {}

        void Start() {
            #if defined(AE_WINDOWS)
                QueryPerformanceCounter( (LARGE_INTEGER*)&m_Start );
            #else
                Start = std::chrono::high_resolution_clock::now();
            #endif
            m_Running = true;
        }

        void Stop() {
            if(m_Running){
                #if defined(AE_WINDOWS)
                    QueryPerformanceCounter( (LARGE_INTEGER*)&m_Now );
                #else
                    End = std::chrono::high_resolution_clock::now();
                #endif
                m_Running = false;
            }
        }

        float GetTimeMilli() const {
            #if defined(AE_WINDOWS)
                if( m_Running )
                {
                    QueryPerformanceCounter( (LARGE_INTEGER*)&m_Now );
                }
                return (float)(m_Now - m_Start) * m_InvFreqMilli;
            #else
                if( m_Running )
                {
                    Stop();
                }
                return std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count();
            #endif
        }

        float GetTimeSec() const {
            return GetTimeMilli() / 1000.0f;
        }

        bool IsRunning() const { return m_Running; }

    };

}
