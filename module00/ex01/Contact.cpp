#include "Contact.hpp"
#include <iostream>

Contact::Contact() : id(-1), firstName(""), lastName(""), nickName(""),
						phoneNumber(""), darkSecret("") {}
void Contact::setContact(int contactId, const std::string &fName,
							const std::string &lName,
							const std::string &nName,
							const std::string &pNumber,
							const std::string &dSecret)
{
	id = contactId;
	firstName = fName;
	lastName = lName;
	nickName = nName;
	phoneNumber = pNumber;
	darkSecret = dSecret;
}
void Contact::displayContact() const
{
	std::cout << id << std::endl;
	std::cout << firstName << std::endl;
	std::cout << lastName << std::endl;
	std::cout << nickName << std::endl;
}