#include "Logger.h"

void ConsoleLogger::Log(std::string message)
{

	std::cout << "Console log: " << level << "," << time(0) 
		<< " ["<<message<<"]"<<std::endl;
}

void FileLogger::Log(std::string message)
{
	std::cout << "File log: " << level << "," << time(0)
		<< " [" << message << "]"<<std::endl;
}

Logger* Logger::createLog(LoggerType type)
{
	switch (type)
	{
	case LoggerType::CONSOLE: return new ConsoleLogger();
	case LoggerType::FILE: return new FileLogger();
	default: assert(false);
	}
}
