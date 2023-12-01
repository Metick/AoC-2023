#include "Utils.h"
#include <fstream>

namespace Utils
{
	namespace File
	{
		std::string ReadFile(const std::string& path)
		{
			std::ifstream file(path);
			std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
			file.close();
			return content;
		}
	}
}
