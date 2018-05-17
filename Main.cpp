#include <iostream>
#include "AESL/Utilities/Log.hpp"
#include "AESL/Utilities/Random.hpp"
#include "AESL/Math/Vector/Vector4.hpp"
#include "AESL/Math/Quaternion/Quaternion.hpp"
#include "AESL/Math/Matrix/Matrix4x4.hpp"
#include "AESL/Utilities/File.hpp"
#include "AESL/Utilities/Timer.hpp"
#include "AESL/Types/Allocator.hpp"
#include "AESL/Types/Optional.hpp"
#include "AESL/Utilities/MainArgsParser.hpp"
#include "AESL/Event/Event.hpp"
#include "AESL/Event/EventHandler.hpp"
#include "AESL/Event/EventCallback.hpp"
#include "AESL/Data/TypeStruct.hpp"
#include "AESL/Data/DataMath/DVector3.hpp"

using namespace AESL;

struct ET{
    void Print(){
        AE_LOG_SUCCESS("Events works wtih classes!");
    }
};

void Print(){
    AE_LOG_SUCCESS("Events works with global!");
}

int main(int argc, char* args[]) {

    std::vector<std::string> Args = MainArgsParser::Instance().ParseMainArgs(argc, args);

    EventHandler TEH;

    Event E;
    TEH.RegisterEvent("Test", &E);

    ET ETI;
    EventCallback<ET> EC(&ETI, &ET::Print);
    EventFunctionCallback EFCT(&Print);
    TEH.RegisterCallback("Test", &EC);
    TEH.RegisterCallback("Test", &EFCT);

    TEH.TriggerEvent("Test");

    if(Args.size() > 0){
        for(size_t i = 0; i < Args.size(); i++){
            if(Args[i] == "-print"){
                if(i < Args.size() - 1){
                    i++;
                    if(Args[i] == "Easter"){
                        AE_LOG_SUCCESS("You have found an easter egg!");
                        std::cin.get();
                        return 0;
                    }
                    else {
                        AE_LOG_NOTE("-print overrides benchmark");
                        AE_LOG_NOTE(Args[i].c_str());
                        std::cin.get();
                        return 0;
                    }
                }
                else{
                    AE_LOG_ERROR("Expected an argument after \"-print\"!");
                    return 0;
                }
            }
            else if(Args[i]=="-pause"){
                AE_LOG_NOTE("Paused...");
                std::cin.get();
            }
        }
    }

    float Times[25] = {};
    AE_LOG_NOTE ("Starting 25 benchmarks...");
    AE_LOG_WARNING ("SIMD optimization not confirmed!\n\n");
    for(size_t i = 0; i < 25; i++){
        AE_LOG_NOTE("Benchmark Starting...");
        Timer T;
        T.Start();

        std::string Name = Random::Name(3, 8);
        Math::DVector4 V = { 2 , 2 , 2, 2 };

        for(float x = 1; x < 100; x++){
            for(float y = 1; y < 100; y++){
                for(float z = 1; z < 100; z++){
                    for(float w = 1; w < 100; w++){
                        V += { i / x, i / y, i / z, i / w };
                    }
                }
            }
        }

        T.Stop();
        Times[i] = T.GetTimeMilli();
        AE_LOG(("Result: X: " + std::to_string(V.X) + " Y: " + std::to_string(V.Y) + " Z: " + std::to_string(V.Z) + " W: " + std::to_string(V.W)).c_str());
        AE_LOG_SUCCESS(("Benchmark \"" + Name + "\" completed in " + std::to_string(Times[i]) + " milliseconds\n").c_str());
        FileIO::WriteToFile("BenchmarkLog.txt", "Benchmark \"" + Name + "\" completed in " + std::to_string(Times[i]) + " milliseconds");
        FileIO::WriteToFile("BenchmarkLog.txt", "Result: X: " + std::to_string(V.X) + " Y: " + std::to_string(V.Y) + " Z: " + std::to_string(V.Z) + " W: " + std::to_string(V.W) + '\n');
    }

    printf("\n");

    float TotalTime = 0.f;

    for(size_t i = 0; i < 25; i++){
        TotalTime += Times[i];
    }

    float AvgTime = TotalTime / 25;

    AE_LOG_SUCCESS (("Benchmarking done in " + std::to_string(TotalTime) + " milliseconds").c_str());
    AE_LOG_SUCCESS (("Average time " + std::to_string(AvgTime) + " milliseconds").c_str());
    FileIO::WriteToFile("BenchmarkLog.txt", "Average Time " + std::to_string(AvgTime) + " milliseconds");
    AE_LOG_NOTE    ("Press enter to close...");

    std::cin.get();
	return 0;
}
