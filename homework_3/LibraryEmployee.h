
#ifndef LIBRARYEMPLOYEE_H
#define LIBRARYEMPLOYEE_H

#include <iostream>

namespace Library
{

	enum class Gender
	{
		NOT_SPECIFIED,
		MALE,
		FEMALE
	};

	enum class Position
	{
		NOT_SPECIFIED,
		LIBRARIANS,
		TECHICIANS,
		ASSISTANTS,
	};

	class LibraryEmployee
	{

	public:
		LibraryEmployee() : age_(0), position_(Position::NOT_SPECIFIED),
			name_(""), surname_(""), gender_(Gender::NOT_SPECIFIED) {
			//id_ = n_++;
		}

		LibraryEmployee(std::istream& cin);

		LibraryEmployee& setAge(unsigned age) { age_ = age; return *this; }
		LibraryEmployee& setPositionCode(Position position) { position_ = position; return *this; }
		LibraryEmployee& setName(std::string name) { name_ = name; return *this; }
		LibraryEmployee& setSurname(std::string surname) { surname_ = surname; return *this; }
		LibraryEmployee& setGender(Gender gender) { gender_ = gender; return *this; }
		LibraryEmployee& setId(unsigned id) { id_ = id; return *this; }

		unsigned getAge() { return age_; }
		Position getPosition() { return position_; }
		std::string getName() { return name_; }
		std::string getSurname() { return surname_; }
		Gender getGender() { return gender_; }
		unsigned getId() { return id_; }
		

	private:
		static unsigned n_;
		unsigned age_, id_;
		Position position_;
		std::string name_;
		std::string surname_;
		Gender gender_;
	};

}

#endif

