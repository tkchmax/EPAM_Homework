#include "Logger.h"
#include "Logger2.h"

int main()
{
	//Factory method
	Logger* console_logger = Logger::createLog(LoggerType::CONSOLE);
	Logger* file_logger = Logger::createLog(LoggerType::FILE);

	console_logger->Log("logging console");
	file_logger->Log("logging file");

	std::cout<<std::endl;
	//NVI method
	Logger2* console_logger2 = new ConsoleLogger2();
	Logger2* file_logger2 = new FileLogger2();
	console_logger2->Log("logging console2");
	file_logger2->Log("logging file2");

	return 0;
}
