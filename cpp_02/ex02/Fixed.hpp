#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    public:
    Fixed();	                                            			//constructor
    Fixed(const Fixed &src);                                			// copy constructor
    ~Fixed();                                               			// destructor

    int		getRawBits(void) const;			                			// Returns the raw value of the fixed point value
    
    void	setRawBits(int const raw);	       	        				// Sets the raw value of the fixed point value
    Fixed	(const float val_float);		            				// Float constructor
    Fixed	(const int val_int);			            				// Int constructor
				
	float	toFloat(void) const;			            				// Returns the floating point value of the fixed point value
	int		toInt(void) const;				            				// Returns the integer value of the fixed point value
	Fixed	&operator = (Fixed const &src_2);	        				// Assignation operator
	bool	operator > (Fixed const &src) const;	    				// Comparison operator >
	bool	operator < (Fixed const &src) const;	    				// Comparison operator <
	bool	operator >= (Fixed const &src) const;	    				// Comparison operator >=
	bool	operator <= (Fixed const &src) const;	    				// Comparison operator <=
	bool	operator == (Fixed const &src) const;	    				// Comparison operator ==
	bool	operator != (Fixed const &src) const;	    				// Comparison operator !=
	Fixed	operator + (Fixed const &src);          					// Arithmetic operator +
	Fixed	operator - (Fixed const &src);          					// Arithmetic operator -
	Fixed	operator * (Fixed const &src);	            				// Arithmetic operator *
	Fixed	operator / (Fixed const &src);	                            // Arithmetic operator
	Fixed	operator ++ ();					                          	// Pre-increment operator
	Fixed	operator ++ (int);				                          	// Post-increment operator
	Fixed	operator -- ();					                          	// Pre-decrement operator
	Fixed	operator -- (int);				                          	// Post-decrement operator
	static Fixed const &min(Fixed const &a, Fixed const &b);	      	// Returns the min of a and b	
	static Fixed const &max(Fixed const &a, Fixed const &b);	      	// Returns the max of a and b
	static Fixed &min(Fixed &a, Fixed &b);						      	// Returns the min of a and b
	static Fixed &max(Fixed &a, Fixed &b);						      	// Returns the max of a and b

	private:

		int					_value;					                    // Fixed point value
		static const int	_fractional_bits = 8;	                    // Number of fractional bits	

};

std::ostream	&operator << (std::ostream &out, Fixed const &src);		// Output stream operator



    private:
};

#endif