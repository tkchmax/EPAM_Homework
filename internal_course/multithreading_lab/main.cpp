#include <iostream>
#include <thread>
#include <sstream>
#include <chrono>
#include "SafeQueue.h"
#define Log(param) Logger(__FILE__, __FUNCTION__, __LINE__, param);

std::condition_variable inbox_cv;
std::mutex inbox_mutex;
SafeQueue<std::string, 3> Inbox;

class Logger
{
public:
	Logger(const Logger&) = delete;
	void operator=(Logger&) = delete;

	template<class T>
	Logger(const char* file, const char* function, int line, const T& param)
	{
		std::stringstream msg;
		std::string indent(4 * depth_, ' ');

		msg << indent << "tid [" << std::hex << std::this_thread::get_id() << "] ["
			<< file << "|" << function << ":" << std::dec << line << "] " << param << "\n";

		Inbox.push(msg.str());
	}

	static void stop() { Inbox.push("STOP_LOGGING"); }

	class entry
	{
	public:
		entry(const entry&) = delete;
		void operator=(entry&) = delete;

		entry() { Logger::depth_++; }
		~entry() { Logger::depth_--; }
	};

private:
	static thread_local  int depth_;
};
thread_local int Logger::depth_ = 0;


void foo_C()
{
	Logger::entry dymmy;
	Log("hello from foo_C!");
}

void foo_B()
{
	Logger::entry dummy;
	Log("hello from foo_B!");
	foo_C();

}

void foo_A()
{
	Logger::entry dummy;
	Log("hello from foo_A!");
	foo_B();
}

int main()
{
	auto writeToFile = [] {
		while (true)
		{
			if (!Inbox.empty())
			{
				auto log = Inbox.pop();
				if (log == "STOP_LOGGING")
					break;

				std::ofstream fout;
				fout.open("Logs.txt", std::ios::app);

				if (!fout.is_open())
					throw std::exception("file error");

				fout << log;
				fout.close();
			}
		}
	};

	std::thread logger_thread(writeToFile);

	Log("hello from main!");

	std::thread t1(foo_A);
	std::thread t2(foo_C);
	foo_A();

	t1.join();
	t2.join();

	Logger::stop();

	logger_thread.join();
}

