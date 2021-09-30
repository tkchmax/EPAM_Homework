#include "Database.h"

void Database::add(const LibraryEmployee& emp)
{
	employees_.push_back(emp);
}

void Database::remove(unsigned id)
{
	employees_.erase(id);
	for (unsigned i = 0; i < employees_.size(); ++i)
		employees_[i].setId(i);

}

void Database::display(unsigned id)
{
	if (employees_.size() == 0)
		std::cout << "EMPTY DATABASE\n";

	for (unsigned i = 0; i < employees_.size(); ++i)
	{
		if (employees_[i].getId() == id)
		{
			std::cout << "------------------\n";
			std::cout << "ID: " << employees_[i].getId() << std::endl;
			std::cout << "NAME: " << employees_[i].getName() << std::endl;
			std::cout << "SURNAME: " << employees_[i].getSurname() << std::endl;
			std::cout << "AGE: " << employees_[i].getAge() << std::endl;

			std::cout << "GENDER: ";
			switch (employees_[i].getGender())
			{
			case Gender::NOT_SPECIFIED:
			default:
				std::cout << "NOT_SPECIFIED\n";
				break;
			case Gender::MALE:
				std::cout << "MALE\n";
				break;
			case Gender::FEMALE:
				std::cout << "FEMALE\n";
				break;
			}

			std::cout << "POSITION: ";
			switch (employees_[i].getPosition())
			{
			case Position::NOT_SPECIFIED:
			default:
				std::cout << "NOT_SPECIDIED\n";
				break;
			case Position::LIBRARIANS:
				std::cout << "LIBRARIANS\n";
				break;
			case Position::ASSISTANTS:
				std::cout << "ASSISTANTS\n";
				break;
			case Position::TECHICIANS:
				std::cout << "TECHICIANS\n";
				break;
			}

			std::cout << "------------------\n";

		}
	}
}
