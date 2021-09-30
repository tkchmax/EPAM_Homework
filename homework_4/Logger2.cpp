#include "Logger2.h"

std::string ConsoleLogger2::getLog(std::string message) const
{
	std::string log = "Console Log2: " + std::to_string(level)
		+","+std::to_string(time(0))+"["+message+"]";
	return log;
}

std::string FileLogger2::getLog(std::string message) const
{
	std::string log = "File Log2: " + std::to_string(level)
		+ "," + std::to_string(time(0)) + "[" + message + "]";
	return log;
}
