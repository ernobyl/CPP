#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits;
	public:
		/* Constructors */
		Fixed();
		Fixed(const int param);
		Fixed(const float param);
		Fixed(const Fixed &other);

		/* Destructor */
		~Fixed();

		/* Operator overload functions */
		Fixed	&operator=(const Fixed &other);
		bool	operator>(Fixed fixed) const;
		bool	operator<(Fixed fixed) const;
		bool	operator>=(Fixed fixed) const;
		bool	operator<=(Fixed fixed) const;
		bool	operator==(Fixed fixed) const;
		bool	operator!=(Fixed fixed) const;

		Fixed	operator+(Fixed fixed) const;
		Fixed	operator-(Fixed fixed) const;
		Fixed	operator*(Fixed fixed) const;
		Fixed	operator/(Fixed fixed) const;

		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		/* Find min functions */
		static			Fixed &min(Fixed &a, Fixed &b);
		static const	Fixed &min(const Fixed &a, const Fixed &b);

		/* Find max functions */
		static			Fixed &max(Fixed &a, Fixed &b);
		static const	Fixed &max(const Fixed &a, const Fixed &b);

		/* Getter function */
		int		getRawBits(void) const;

		/* Setter function */
		void	setRawBits(int const raw);

		/* Converter functions */
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif