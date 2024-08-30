#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon();
		~Weapon();
		const std::string	getType() const;
		void 				setType(const std::string &newType);
};



#endif