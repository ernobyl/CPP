#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits;
    public:
        Fixed();
        Fixed(const int param);
        Fixed(const float param);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);

        ~Fixed();

        int		getRawBits(void) const;
        void	setRawBits(int const raw);
		int		toInt(void) const;
        float	toFloat(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif