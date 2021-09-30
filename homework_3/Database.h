#ifndef DATABASE_H
#define DATABASE_H

#include "LibraryEmployee.h"
#include "MyVector.h"
#include <vector>
using namespace Library;

class Database
{
public:
	void add(const LibraryEmployee& emp);
	void remove(unsigned id);
	LibraryEmployee& getEmployee(unsigned id);

	void display(unsigned id);
	void displayAll();

	unsigned size() { return employees_.size(); }

private:
	MyVector<LibraryEmployee> employees_;
	//std::vector<LibraryEmployee> employees_;
};

#endif
