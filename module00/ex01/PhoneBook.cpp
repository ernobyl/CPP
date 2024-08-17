#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : oldestContactIndex(0), contactCount(0), nextId(0) {}

void PhoneBook::addContact()
{
	std::string fName, lName, nName, pNumber, dSecret;

	std::cout << "Enter First Name: ";
    std::getline(std::cin, fName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nName);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, pNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, dSecret);

	if (fName.empty() || lName.empty() || nName.empty() || pNumber.empty() || dSecret.empty())
	{
        std::cout << "All fields must be filled!" << std::endl;
        return;
	}
	
	Contact newContact;
    newContact.setContact(nextId, fName, lName, nName, pNumber, dSecret);

    if (contactCount < 8)
	{
        contacts[contactCount] = newContact;
        contactCount++;
    }
	else
	{
        contacts[oldestContactIndex] = newContact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
    nextId++;
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << std::right << "Index"
              << '|' << std::setw(10) << std::right << "First Name"
              << '|' << std::setw(10) << std::right << "Last Name"
              << '|' << std::setw(10) << std::right << "Nickname" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; ++i)
	{
        std::cout << std::setw(10) << std::right << contacts[i].getId()
                  << '|' << std::setw(10) << std::right << contacts[i].getFirstName().substr(0, 9) + (contacts[i].getFirstName().length() > 9 ? "." : "")
                  << '|' << std::setw(10) << std::right << contacts[i].getLastName().substr(0, 9) + (contacts[i].getLastName().length() > 9 ? "." : "")
                  << '|' << std::setw(10) << std::right << contacts[i].getNickName().substr(0, 9) + (contacts[i].getNickName().length() > 9 ? "." : "") << std::endl;
    }
}

void PhoneBook::displayContactByIndex(int index) const
{
    if (index < 0 || index >= contactCount)
	{
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    contacts[index].displayContact();
}