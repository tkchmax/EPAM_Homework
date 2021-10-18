#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>

struct Person
{
	Person() : name_(""), phone_(""), adress_("") {}
	Person(const std::string& name, const std::string& phone, const std::string& adress) : name_(name), phone_(phone), adress_(adress) {}
	bool empty()
	{
		if (name_ == "")
			return true;
		return false;
	}
	bool operator==(const Person& other)
	{
		if (name_ == other.name_ && phone_ == other.phone_ && adress_ == other.adress_)
			return true;
		return false;
	}

	std::string name_;
	std::string phone_;
	std::string adress_;
};

class HashTable
{
public:
	HashTable();
	HashTable(unsigned int tableCapacity);

	void add(const std::string& name, const std::string& phone, const std::string& adress);
	void remove(const std::string& name);
	std::string get_phone(const std::string& name);
	std::string get_adress(const std::string& name);
	std::string get_name(const std::string& phone);
private:
	unsigned int hash_(const std::string& key);
	void add_(std::vector<Person>& table, unsigned int hash, const Person& person);
	void resize_();
private:
	std::vector<Person> tableByName_;
	std::vector<Person> tableByPhone_;
	unsigned int tableSize_;
	unsigned int tableCapacity_;
	
};

#endif

