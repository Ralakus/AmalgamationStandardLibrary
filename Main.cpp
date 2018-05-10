#include <iostream>
#include "AESL/Utilities/Log.hpp"
#include "AESL/Utilities/Random.hpp"
#include "AESL/Math/Vector/Vector3.hpp"
#include "AESL/Math/Vector/Vector4.hpp"

using namespace AESL;

int main()
{

    unsigned long long int Frequency;
    float InvFreqMilli;
    QueryPerformanceFrequency( (LARGE_INTEGER*)&Frequency );
    InvFreqMilli = 1.0f / (float)((double)Frequency / 1000.0);

    unsigned long long int Start;
    QueryPerformanceCounter( (LARGE_INTEGER*)&Start );
    unsigned long long int End;

    AE_LOG ("Starting Benchmark...");

    Math::Vector4 V;

    for(float x = 0; x < 100; x++){
        for(float y = 0; y < 100; y++){
            for(float z = 0; z < 100; z++){
                for(float w = 0; w < 100; w++){
                    V /= { x, y, z, w };
                }
            }
        }
    }

    QueryPerformanceCounter( (LARGE_INTEGER*)&End );

    AE_LOG_SUCCESS (("Benchmark completed in: " + std::to_string((float)(End - Start) * InvFreqMilli) + " miliseconds").c_str());

    AE_LOG ("Gernating Random Name...");
    for(size_t i = 0; i < 50; i++){
        AE_LOG((Random::Name(3, 8) + '\n').c_str());
    }
    std::cin.get();
	return 0;
}
