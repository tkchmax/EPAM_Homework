#include "Logger.h"

constexpr int getMaxInt(int nDigits)
{
	if (nDigits < 0)
		throw std::invalid_argument("n<0");

	if (nDigits > 9)
		nDigits = 9;

	int result = 0;

	for (unsigned i = 0, tmp = 1; i < nDigits; ++i, tmp *= 10)
		result += 9 * tmp;

	return result;
}

int main()
{
	ConsoleLogger* cl = new ConsoleLogger();
	FileLogger* fl = new FileLogger();

	cl->Log(1, 2, 3, "something wrong here");
	std::cout << std::endl;
	fl->Log(3124, 2134);

	std::cout << std::endl << getMaxInt(4);

}

