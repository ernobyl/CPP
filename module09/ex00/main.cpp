#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Expected 1 argument: <filename>\n";
		return 1;
	}
	std::string arg = argv[1];
	BitcoinExchange btc("data.csv");
	btc.processInputFile(arg);

	return 0;
}