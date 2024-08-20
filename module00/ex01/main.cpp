#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
	PhoneBook   phonebook;
	std::string cmd;

	while(1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
		{
			if (phonebook.displayContacts())
			{
				std::cout << "Enter index of contact to display: ";
				while (1)
				{
					int index;
					std::cin >> index;
					std::cin.ignore();
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cout << "Invalid input. Please enter a number." << std::endl;
						break;
					}
					else
					{
						phonebook.displayContactByIndex(index - 1);
						break;
					}
				}
			}
		}
		else if (cmd == "EXIT")
			break;
		else if (cmd == "")
			continue;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}
