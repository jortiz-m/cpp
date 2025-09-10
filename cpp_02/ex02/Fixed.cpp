#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {}

Fixed::Fixed(const int inInt) 
{
	value = inInt << fractionalNbr;
}

Fixed::Fixed(const float inFloat) 
{
	value = roundf(inFloat * (1 << fractionalNbr));
}

Fixed::Fixed(const Fixed& other) : value(other.value) 
{
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
}

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

Fixed	Fixed::operator+(const Fixed& other) const 
{
	return Fixed(value + other.value);
}

Fixed	Fixed::operator-(const Fixed& other) const
{

	return Fixed(value - other.value);
}

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
