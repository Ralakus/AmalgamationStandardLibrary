#pragma once

#include <fstream>

namespace AESL {

	class File {

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
            std::ofstream OutputFile;
            OutputFile.open(NameAndLocation, Mode);
            OutputFile << Data << '\n';
            OutputFile.close();
		}

	};

}
