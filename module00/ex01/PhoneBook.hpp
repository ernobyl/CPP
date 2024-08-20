#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		oldestContactIndex;
		int		contactCount;
	
	public:
		PhoneBook();
		void	addContact();
		int 	displayContacts() const;
		void 	displayContactByIndex(int index) const;
};

#endif