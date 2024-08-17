#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook   phonebook;
    std::string cmd;

    while(1)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT)";
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
            phonebook.addContact();
        else if (cmd == "SEARCH")
        {
            phonebook.displayContacts();
            int index;
            std::cout << "Enter index of contact to display.";
            std::cin >> index;
            std::cin.ignore();
            phonebook.displayContactByIndex(index);
        }
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}