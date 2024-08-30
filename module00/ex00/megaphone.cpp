#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		(void)argv;
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for(int i = 1; i < argc; ++i)
		{
			for(int j = 0; argv[i][j]; ++j)
				argv[i][j] = std::toupper(static_cast<unsigned char>(argv[i][j])); 
		}
		for(int i = 1; argv[i]; ++i)
			std::cout << argv[i];
		std::cout << std::endl;
	}
	return 0;
}