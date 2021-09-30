#include "LibraryEmployee.h"

namespace Library
{

	LibraryEmployee::LibraryEmployee(std::istream& cin)
	{
		std::cout << "Enter Name: "; cin >> name_;
		std::cout << "Enter Surname: "; cin >> surname_;
		std::cout << "Enter Age: "; cin >> age_;

		std::cout << "Enter Gender: ";
		std::string gender;
		cin >> gender;
		if (gender == "male")
			gender_ = Gender::MALE;
		else if (gender == "female")
			gender_ = Gender::FEMALE;
		
		std::cout << "\nChoose avaliable position:\n";
		std::cout << " 1. LIBRARIANS\n 2. TECHICIANS\n 3. ASSISTANTS\n";
		int choose;
		std::cout << ">> "; cin >> choose;
		switch (choose)
		{
		case 1:
			position_ = Position::LIBRARIANS;
			break;
		case 2:
			position_ = Position::TECHICIANS;
			break;
		case 3:
			position_ = Position::ASSISTANTS;
			break;
		}
	
		id_ = n_++;
	}

	unsigned LibraryEmployee::n_ = 0;

}
