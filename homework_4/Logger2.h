#ifndef LOGGER2_H
#define LOGGER2_H

#include <iostream>
#include <string>

//NVI idiom
class Logger2
{
public:
	void Log(std::string message) { std::cout << getLog(message) << std::endl; }
private:
	virtual std::string getLog(std::string) const = 0;
protected:
	int level;
};

class ConsoleLogger2 : public Logger2
{
private:
	std::string getLog(std::string) const override;
};

class FileLogger2 : public Logger2
{
private:
	std::string getLog(std::string) const override;
};

#endif