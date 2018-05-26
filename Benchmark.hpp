#pragma once

#include "AESL/Utilities/File.hpp"
#include "AESL/Utilities/Timer.hpp"
#include "AESL/Utilities/Log.hpp"
#include "AESL/Utilities/Random.hpp"
#include "AESL/Math/Vector/Vector4.hpp"
#include "AESL/Event/EventHandler.hpp"

namespace Amalgamation {

	class Benchmark {
	public:
		static void StartMath() {
			float Times[25] = {};
			File OutputFile("BenchmarkLog.txt");
			AE_LOG_NOTE("Starting 25 benchmarks...");
			AE_LOG_WARNING("SIMD optimization not confirmed!\n\n");
			for (size_t i = 0; i < 25; i++) {
				AE_LOG_NOTE("Benchmark Starting...");
				Timer T;
				T.Start();

				std::string Name = Random::Name(3, 8);
				//TypeStruct<MATH_TYPE, 4> V = { 2 , 2 , 2, 2 };
				Math::Vector4 V = { 2 , 2 , 2, 2 };

				for (float x = 1; x < 100; x++) {
					for (float y = 1; y < 100; y++) {
						for (float z = 1; z < 100; z++) {
							for (float w = 1; w < 100; w++) {
								V += { i / x, i / y, i / z, i / w };
							}
						}
					}
				}

				T.Stop();
				Times[i] = T.GetTimeMilli();
				AE_LOG(("Result: X: " + std::to_string(V.X) + " Y: " + std::to_string(V.Y) + " Z: " + std::to_string(V.Z) + " W: " + std::to_string(V.W)).c_str());
				AE_LOG_SUCCESS(("Benchmark \"" + Name + "\" completed in " + std::to_string(Times[i]) + " milliseconds\n").c_str());
                OutputFile.Write("Benchmark \"" + Name + "\" completed in " + std::to_string(Times[i]) + " milliseconds\n");
                OutputFile.Write("Result: X: " + std::to_string(V.X) + " Y: " + std::to_string(V.Y) + " Z: " + std::to_string(V.Z) + " W: " + std::to_string(V.W) + '\n');
				//FileIO::WriteToFile("BenchmarkLog.txt", "Benchmark \"" + Name + "\" completed in " + std::to_string(Times[i]) + " milliseconds");
				//FileIO::WriteToFile("BenchmarkLog.txt", "Result: X: " + std::to_string(V.X) + " Y: " + std::to_string(V.Y) + " Z: " + std::to_string(V.Z) + " W: " + std::to_string(V.W) + '\n');
			}

			printf("\n");

			float TotalTime = 0.f;

			for (size_t i = 0; i < 25; i++) {
				TotalTime += Times[i];
			}

			AE_LOG_SUCCESS(("Benchmarking done in " + std::to_string(TotalTime) + " milliseconds").c_str());
		}
	};

}
