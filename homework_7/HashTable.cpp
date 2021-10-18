#include "HashTable.h"

HashTable::HashTable()
{
	tableCapacity_ = 0;
	tableSize_ = 0;
}

HashTable::HashTable(unsigned int tableCapacity)
{
	tableCapacity_ = tableCapacity;
	tableSize_ = 0;
	tableByName_ = std::vector<Person>(tableCapacity_);
	tableByPhone_ = std::vector<Person>(tableCapacity_);
}


void HashTable::add(const std::string& name, const std::string& phone, const std::string& adress)
{
	if (tableSize_ >= 0.7*tableCapacity_)
		resize_();

	Person p(name, phone, adress);
	add_(tableByName_, hash_(name), p);
	add_(tableByPhone_, hash_(phone), p);
	tableSize_++;

}

void HashTable::remove(const std::string& name)
{
	unsigned int key = hash_(name);
	while (tableByName_[key].name_ != name)
	{
		if (tableByName_[key].name_ == "")
			throw std::out_of_range("Person not found");
		key++;
	}

	unsigned int phone_key = hash_(tableByName_[key].phone_);
	tableByPhone_[phone_key] = std::move(Person());
	tableByName_[key] = std::move(Person());

	tableSize_--;
}

std::string HashTable::get_phone(const std::string& name)
{
	return tableByName_[hash_(name)].phone_;
}

std::string HashTable::get_adress(const std::string& name)
{
	return tableByName_[hash_(name)].adress_;
}

std::string HashTable::get_name(const std::string& phone)
{
	return tableByPhone_[hash_(phone)].name_;
}

unsigned int HashTable::hash_(const std::string& key)
{
	unsigned long hash = 5381;
	int symbol;

	const char* cstr = key.c_str();
	while (symbol = *cstr++)
		hash = ((hash << 5) + hash) + symbol;

	return hash % tableCapacity_;
}

void HashTable::add_(std::vector<Person>& table, unsigned int key, const Person& person)
{
	while (!table[key].empty())
	{
		if (table[key].name_ == person.name_)
			throw std::logic_error("name is already exist");
		if (table[key].phone_ == person.phone_)
			throw std::logic_error("phone is already exist");
		key++;
		key %= tableCapacity_;
	}
	table[key] = person;
}

void HashTable::resize_()
{
	unsigned int newCapacity = (tableCapacity_ == 0) ? 10 : tableCapacity_ * 2;
	HashTable newTable(newCapacity);

	for (auto iter = tableByName_.begin(); iter != tableByName_.end(); ++iter)
		newTable.add(iter->name_, iter->phone_, iter->adress_);

	*this = newTable;
}

