#define MATH_TYPE float

#include <iostream>
#include "AESL/Utilities/Log.hpp"
#include "AESL/Utilities/MainArgsParser.hpp"
#include "AESL/Event/EventHandler.hpp"
#include "AESL/Task/ThreadPool.hpp"

#include "Benchmark.hpp"

using namespace Amalgamation;

int main(int argc, char* args[]) {
    std::vector<std::string> Args = MainArgsParser::Instance().ParseMainArgs(argc, args);

	EventHandler EventSystem;

	Event Benchmark;
	EventSystem.RegisterEvent("StartMath", &Benchmark);

	EventFunctionCallback StartBenchmark(Benchmark::StartMath);
	EventSystem.RegisterCallback("StartMath", &StartBenchmark);

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
			/*else if (Args[i] == "-benchmark") {
				EventSystem.TriggerEvent("StartMath");
			}*/
        }
    }
	else {
		AE_LOG_ERROR("Enter \"-benchmark\" as argument to run math benchmark otherwise nothing will happen");
	}

	EventSystem.TriggerEvent("StartMath");

    AE_LOG_NOTE("Press enter to close...");


    std::cin.get();
	return 0;
}
