#include "HashTable.h"

int main()
{
	HashTable ht(1);
	ht.add("a", "1", "c1");
	ht.add("aa", "2", "c2");
	ht.add("aaa", "3", "c3");
	ht.add("aaaa", "4", "c4");

	std::cout << ht.get_phone("a")<<std::endl;
	std::cout << ht.get_phone("aa")<<std::endl;
	std::cout << ht.get_phone("aaa")<<std::endl;
	std::cout << ht.get_phone("aaaa")<<std::endl;
	std::cout << "---\n";
	std::cout << ht.get_name("1") << std::endl;
	std::cout << ht.get_name("2") << std::endl;
	std::cout << ht.get_name("3") << std::endl;
	std::cout << ht.get_name("4") << std::endl;
	std::cout << "---\n";
	std::cout << ht.get_adress("a") << std::endl;
	std::cout << ht.get_adress("aa") << std::endl;
	std::cout << ht.get_adress("aaa") << std::endl;
	std::cout << ht.get_adress("aaaa") << std::endl;

}

