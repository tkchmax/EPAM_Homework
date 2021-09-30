#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <ctime>
#include <assert.h>

//Factory method
enum class LoggerType
{
	CONSOLE,
	FILE
};

class Logger
{
public:
	virtual void Log(std::string mesasge) = 0;
	static Logger* createLog(LoggerType type);
protected:
	int level;
};

class ConsoleLogger : public Logger
{
public:
	void Log(std::string message) override;
};	

class FileLogger : public Logger
{
public:
	void Log(std::string message) override;
};

#endif