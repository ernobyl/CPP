#include <iostream>
#include <unistd.h>

#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	int seedcount = 6;
	std::cout << "Random seed no. 1" << std::endl;
	for (int i = 0; i < seedcount; i++)
	{
		Base* random1 = generate();
		identify(random1);
		identify(*random1);
		delete(random1);
		if (i < seedcount - 1)
			std::cout << "Random seed no. " << i + 2 << " in 1 second..." << std::endl;
		sleep(1);
	}
	return 0;
}