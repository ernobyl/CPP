#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

std::string read_file(std::string &filename)
{
	if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".csv")
	{
		std::cout << "Invalid file extension. (Expected '.csv')\n";
		return "";
	}
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "Error opening file: " << filename << "\n";
        return "";
	}
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Expected 1 argument: <filename>\n";
		return 1;
	}
	std::string arg = argv[1];
	std::string file_content = read_file(arg);
	if (file_content.empty())
	{
		std::cout << "File content empty\n";
		return 1;
	}
	DatesAndPrices data(file_content);

	return 0;
}