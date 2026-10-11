/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:28:13 by rodantec          #+#    #+#             */
/*   Updated: 2026/01/12 09:28:13 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed:: Fixed() : _value(0)
{
     std::cout << "Default constructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &other)
{
     std::cout << "Copy assignment operator called" << std::endl;
     _value = other.getRawBits();
     return (*this);
}

Fixed::Fixed(const Fixed &other)
{
     std::cout << "Copy constructor called" << std::endl;
     *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits called" << std::endl;
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits called" << std::endl;
    _value = raw;
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
     _value = i << _base ;
}
Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(f * (1 << _base));
}
float Fixed::toFloat( void ) const
{
    return((float)_value / (1 << _base));
}

int Fixed::toInt( void ) const
{
    return(_value >> _base);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}
