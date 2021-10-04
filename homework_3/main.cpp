#include "Database.h"
#include <map>
#include <string>
#include <vector>
#include <sstream>

#include <iomanip>

template<typename T>
void show(MyVector<T> v)
{
	if (v.size() == 0)
		std::cout << "empty\n";
	for (unsigned i = 0; i < v.size(); ++i)
		std::cout << v[i];
	std::cout << "\nsize: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "----\n";
}
void vector_tests()
{
	MyVector<int> v1(10);

	for (unsigned i = 0; i < v1.size(); ++i)
		v1[i] = i;

	v1.push_back(10);
	v1.push_back(11);
	v1.push_back(12);

	std::cout << "v1: ";
	show<int>(v1);

	v1.pop_back();

	std::cout << "v1: ";
	show<int>(v1);

	MyVector<int> v2 = v1; //MyVector(const MyVector&)

	std::cout << "v2: ";
	show<int>(v2);

	MyVector<int> v3; //operator=(const MyVector&)
	v3 = v2;

	std::cout << "v3: ";
	show<int>(v3);

	MyVector<int> v4 = std::move(v3); // MyVector(MyVector&&)

	std::cout << "v4: ";
	show<int>(v4);
	std::cout << "v3: ";
	show<int>(v3);

	std::cout << "current v4 capacity: " << v4.capacity() << std::endl;
	v4.reserve(1000);
	std::cout << "after reserve: " << v4.capacity() << std::endl;

	MyVector<std::string> v5;
	v5.push_back("one");
	v5.push_back("two");
	v5.push_back("three");
	for (unsigned i = 0; i < v5.size(); ++i)
		std::cout << v5[i] << std::endl;

}

class Handler
{
public:
	Handler(Database* db) : database(db) {}
	virtual void handle(std::string* parameters) = 0;
protected:
	Database* database;
};

class AddEmployeeHandler : public Handler
{
public:
	AddEmployeeHandler(Database* db) : Handler(db) {}
	void handle(std::string* parameters) override
	{
		LibraryEmployee emp(std::cin);
		database->add(emp);
	}
};

class RemoveHandler : public Handler
{
public:
	RemoveHandler(Database* db) : Handler(db) {}
	void handle(std::string* parameters) override
	{
		int id = stoi(*(++parameters));

		if (id < 0 || id >= database->size())
			throw std::invalid_argument("id < 0");

		database->remove(id);
	}
};

class DisplayHandler : public Handler
{
public:
	DisplayHandler(Database* db) : Handler(db) {}
	void handle(std::string* parameters) override
	{
		int id;
		try
		{
			id = stoi(*(++parameters));
		}
		catch (std::invalid_argument& e)
		{
			for (unsigned i = 0; i < database->size(); ++i)
				database->display(i);
			return;

		}

		if (id < 0 || id >= database->size())
			throw std::invalid_argument("id < 0");

		database->display(id);

	}
};

class HelpHandler : public Handler
{
public:
	HelpHandler(Database* db) : Handler(db) {}
	void handle(std::string* parameters) override
	{
		std::cout << "Commands:\n";
		std::cout << std::setw(15) << std::left << "  add" << std::setw(30) << std::left << "add new employee" << std::endl;
		std::cout << std::setw(15) << std::left << "  ls <id>" << std::setw(30) << std::left << "display employee[id] infomation" << std::endl;
		std::cout << std::setw(15) << std::left << "  ls" << std::setw(30) << std::left << "display all employees information" << std::endl;
		std::cout << std::setw(15) << std::left << "  rm <id>" << std::setw(30) << std::left << "remove employee[id] from database" << std::endl;
	}
};

class ClearHandler : public Handler
{
public:
	ClearHandler(Database* db) : Handler(db) {}
	void handle(std::string* parameters)
	{
		system("cls");
	}
};



inline MyVector<std::string> ParseCommand(std::string command)
{
	MyVector<std::string> v;
	std::stringstream ss(command);

	std::string temp;
	while (ss)
	{
		ss >> temp;
		v.push_back(temp);
	}

	if (v.size() > 1) // !
		v.pop_back(); //

	return v;

}
int main()
{

	Database database;

	std::map<std::string, Handler*> handlers;
	handlers["add"] = new AddEmployeeHandler(&database);
	handlers["ls"] = new DisplayHandler(&database);
	handlers["rm"] = new RemoveHandler(&database);
	handlers["help"] = new HelpHandler(&database);
	handlers["cls"] = new ClearHandler(&database);

	std::string input;
	std::vector<std::string> parameters;

	while (true)
	{
		std::cout << ">> ";
		std::getline(std::cin, input);
		MyVector<std::string> parameters = ParseCommand(input);

		if (parameters[0] == "")
			continue;
		else if(parameters[0] == "q")
			break;

		std::string command = parameters[0];
		try
		{
			handlers.at(command)->handle(&parameters[0]);
		}
		catch (std::out_of_range& e)
		{
			printf("\033[31mERROR: command not found\033[0m\n");
		}
		catch (std::invalid_argument& e)
		{
			printf("\033[31mERROR: invalid parameters\033[0m\n");

		}
	}
}

