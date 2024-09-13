#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

/* Constructors */
Fixed::Fixed() : _fixedPointValue(0)
{
    //std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int param)
{
    std::cout << "Int constructor called." << std::endl;
    _fixedPointValue = param << _fractionalBits;
}

Fixed::Fixed(const float param)
{
    //std::cout << "Float constructor called." << std::endl;
    _fixedPointValue = roundf(param * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
    //std::cout << "Copy constructor called" << std::endl;
}

/* Destructor */
Fixed::~Fixed()
{
    //std::cout << "Destructor called." << std::endl;
}

/* Operator overload functions */
Fixed &Fixed::operator=(const Fixed &other)
{
    //std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
        this->_fixedPointValue = other._fixedPointValue;
    return (*this);
}

bool Fixed::operator>(Fixed fixed) const
{
    return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(Fixed fixed) const
{
    return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed) const
{
    return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed) const
{
    return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed) const
{
    return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed) const
{
    return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const
{
    return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
    return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
    return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
    return (this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++()
{
    this->_fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator--()
{
    this->_fixedPointValue--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
   Fixed temp(*this);
   this->_fixedPointValue++;
   return (temp);
}

Fixed Fixed::operator--(int)
{
   Fixed temp(*this);
   this->_fixedPointValue--;
   return (temp);
}

/* Find min functions */
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}

/* Find max functions */
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}

/* Getter function */
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

/* Setter function */
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}

/* Converter functions */
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