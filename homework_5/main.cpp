#include <iostream>
#include <memory>
#include "MyUnique_ptr.h"
#include "MyShared_ptr.h"
#include <cassert>

using namespace std;

void shared_tests()
{
	std::shared_ptr<int> p1(new int(5));
	MyShared_ptr<int> t1(new int(5));
	assert(p1.use_count() == t1.use_count());

	std::shared_ptr<int> p2(p1);
	MyShared_ptr<int> t2(t1);
	assert(p2.use_count() == t2.use_count() && p1.use_count() == t1.use_count() && *p1.get() == *t1.get());

	p1.reset();
	t1.reset();
	assert(p2.use_count() == t2.use_count() && p1.use_count() == t1.use_count() && *p2.get() == *t2.get());

	std::shared_ptr<int> p3 = std::shared_ptr<int>(new int(100));
	MyShared_ptr<int> t3 = MyShared_ptr<int>(new int(100));
	assert(p3.use_count() == t3.use_count() && *p3.get() == *t3.get());

	std::shared_ptr<int> p4 = std::shared_ptr<int>(p3);
	MyShared_ptr<int> t4 = MyShared_ptr<int>(t3);
	assert(p4.use_count() == t4.use_count() && *p4.get() == *t4.get() && p4.use_count() == t3.use_count());

	std::cout << "SHARED TESTS PASSED\n";
}

int main()
{
	shared_tests();
}


