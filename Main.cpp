#include <iostream>
#include "AESL/Utilities/Log.hpp"
#include "AESL/Utilities/Random.hpp"
#include "AESL/Math/Vector/Vector3.hpp"
#include "AESL/Math/Vector/Vector4.hpp"

#include <chrono>

using namespace AESL;

using Clock = std::chrono::high_resolution_clock;

int main()
{

    auto Start = Clock::now();
    auto End   = Clock::now();

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

    End = Clock::now();

    AE_LOG_SUCCESS (("Benchmark completed in: " + std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(End - Start).count()) + " microseconds").c_str());

    AE_LOG ("Gernating Random Name...");
    for(size_t i = 0; i < 1; i++){
        AE_LOG((Random::Name(3, 8) + '\n').c_str());
    }
    std::cin.get();
	return 0;
}
