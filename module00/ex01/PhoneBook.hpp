#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		oldestContactIndex;
		int		contactCount;
		int		nextId;
	
	public:
		PhoneBook();
		void addContact(const Contact &newContact);
		void displayContacts() const;
};

#endif