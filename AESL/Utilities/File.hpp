#pragma once

#include <fstream>

namespace AESL {

	class FileIO {

	public:

		static std::string ReadFile(const std::string& filepath) {
			std::ifstream ifs((filepath).c_str());
			std::string content(
				std::istreambuf_iterator<char>(ifs.rdbuf()),
				std::istreambuf_iterator<char>()
			);
			return content;
		}

		static std::string ReadFile(const char* filepath) {
			std::ifstream ifs(filepath);
			std::string content(
				std::istreambuf_iterator<char>(ifs.rdbuf()),
				std::istreambuf_iterator<char>()
			);
			return content;
		}

		static void WriteToFile(const std::string& NameAndLocation, const std::string& Data, unsigned int Mode = std::ios::app) {
            static std::ofstream OutputFile;
            static std::string LastFile = "";
            static unsigned int LastMode = 0;
            if(NameAndLocation == LastFile && Mode == LastMode){
                OutputFile << Data << '\n';
            }
            else{
                OutputFile.close();
                OutputFile.open(NameAndLocation, static_cast<std::ios_base::open_mode>(Mode));
            }
            LastFile = NameAndLocation;
            LastMode = Mode;
		}

	};

}
