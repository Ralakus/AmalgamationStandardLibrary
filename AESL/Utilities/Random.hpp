#include <string>

namespace AESL{

    class Random{

    public:



        static size_t Uint(size_t Min, size_t Max){
            RandomizeOnce();
            return rand() % Max + Min;
        }

        static bool RandomizeOnce(){
            static bool m_DidRand = false;
            if(!m_DidRand)){
                srand(time(nullptr));
                m_DidRand = true;
            }
            return m_DidRand;
        }

    };

}
