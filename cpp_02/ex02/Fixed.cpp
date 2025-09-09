#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {}

Fixed::Fixed(const int value) 
{
	value = value << fractionalNbr;
}

Fixed::Fixed(const float value) 
{
	value = roundf(value * (1 << fractionalNbr));
}

Fixed::Fixed(const Fixed& other) : value(other.value) 
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& other) 
{
	if (this !=& other) {
		value = other.value;
	}
	return *this;
}

Fixed::~Fixed(void) 
{
	std::cout << "Destructor called" << std::endl;
}

// Comparative operators

bool	Fixed::operator>(const Fixed& other) const 
{
	return (value > other.value);
}

bool	Fixed::operator<(const Fixed& other) const 
{
	return (value < other.value);
}

bool	Fixed::operator>=(const Fixed& other) const 
{
	return (value >= other.value);
}

bool	Fixed::operator<=(const Fixed& other) const 
{
	return (value <= other.value);
}

bool	Fixed::operator!=(const Fixed& other) const 
{
	return (value != other.value);
}

bool	Fixed::operator==(const Fixed& other) const 
{
	return (value == other.value);
}

// Arithmetic operators

Fixed	Fixed::operator+(const Fixed& other) const 
{
	return Fixed(value + other.value);
}

Fixed	Fixed::operator-(const Fixed& other) const
{

	return Fixed(value - other.value);
}

// It fails if I return directly like other functions
Fixed Fixed::operator*(const Fixed& other) const 
{
    Fixed result;
    result.value = (value * other.value) / (1 << fractionalNbr);
    return result;
}

Fixed	Fixed::operator/(const Fixed& other) const 
{
	return Fixed(static_cast<float>(value) / other.value);
}

// Increment/Decrement operators

Fixed	&Fixed::operator++(void) 
{
	value++;
	return *this;
}

Fixed	&Fixed::operator--(void) 
{
	value--;
	return *this;
}

Fixed	Fixed::operator++(int) 
{
	Fixed result;
	result.value = value;
	value++;
	return result;
}

Fixed	Fixed::operator--(int) 
{
	Fixed result;
	result.value = value;
	value--;
	return result;
}

// Min/Max

Fixed& Fixed::min(Fixed& a, Fixed& b) 
{
	return (a.value < b.value) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) 
{
	return (a.value > b.value) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{
	return (a.value < b.value) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
	return (a.value > b.value) ? a : b;
}

std::ostream &operator<<(std::ostream& out, const Fixed& fixed) 
{
	out << fixed.toFloat();
	return out;
}

float	Fixed::toFloat(void) const 
{
	return (static_cast<float>(value) / (1 << fractionalNbr));
}

int	Fixed::toInt(void) const 
{
	return (value >> fractionalNbr);
}
