#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	private:
		int			id;
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;
	
	public:
		Contact();
		void		setContact(const std::string &fName,
								const std::string &lName, const std::string &nName,
								const std::string &pNumber, const std::string &dSecret);
		void 		displayContact() const;
		int			getId() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkSecret() const;
};

#endif