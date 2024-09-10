#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int param)
{
    std::cout << "Int constructor called." << std::endl;
    _fixedPointValue = param << _fractionalBits;
}

Fixed::Fixed(const float param)
{
    std::cout << "Float constructor called." << std::endl;
    _fixedPointValue = roundf(param * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
        this->_fixedPointValue = other._fixedPointValue;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}

int Fixed::toInt(void) const
{
    return _fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}