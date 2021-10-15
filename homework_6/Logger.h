#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <ctime>
#include <string>

template<typename Derived>
class Logger
{
public:
	template<typename... Args>
	void Log(Args... args)
	{
		std::time_t now = std::time(nullptr);

		std::string header = "Time: " + std::to_string(time(0)) + " [";
		std::string footer = "]\n";

		self()->me();
		self()->LogImpl(header, std::forward<Args>(args)..., footer);
	}
private:
	Derived* self()
	{
		return static_cast<Derived*>(this);
	}
};

class ConsoleLogger : public Logger<ConsoleLogger>
{
	friend class Logger<ConsoleLogger>;
private:
	template<typename Arg>
	void LogImpl(Arg arg)
	{
		std::cout << arg << " ";
	}

	template<typename First, typename... Args>
	void LogImpl(First first, Args... args)
	{
		LogImpl(first);
		LogImpl(args...);
	}

	void me() { std::cout << "ConsoleLogger  "; }
	

};

class FileLogger : public Logger<FileLogger>
{
	friend class Logger<FileLogger>;
private:
	template<typename Arg>
	void LogImpl(Arg arg)
	{
		std::cout << arg << " ";
	}

	template<typename First, typename... Args>
	void LogImpl(First first, Args... args)
	{
		LogImpl(first);
		LogImpl(args...);
	}

	void me() { std::cout << "FileLogger  "; }


};

#endif
