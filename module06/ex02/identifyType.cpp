#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	std::srand(std::time(0));
	int r = std::rand() % 3;
	switch (r)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "type: C" << std::endl;
	else
		std::cout << "unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{ 
		A& a = (dynamic_cast<A&>(p));
		std::cout << "type: A" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}
	try
	{ 
		B& b = (dynamic_cast<B&>(p));
		std::cout << "type: B" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}
	try
	{ 
		C& c = (dynamic_cast<C&>(p));
		std::cout << "type: C" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}
	std::cout << "unknown type" << std::endl;
}