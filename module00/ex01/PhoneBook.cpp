#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : oldestContactIndex(0), contactCount(0), nextId(0) {}

void PhoneBook::addContact(const Contact &newContact)
{
	Contact contactWithId = newContact;
	contactWithId.setContact(
		nextId,
		contactWithId.getFirstName(),
		contactWithId.getLastName(),
		contactWithId.getNickName(),
		contactWithId.getPhoneNumber(),
		contactWithId.getDarkSecret()
	);
	if (contactCount < 8)
	{
		contacts[contactCount] = contactWithId;
		oldestContactIndex = (oldestContactIndex + 1) % 8;
	}
	nextId++;
}