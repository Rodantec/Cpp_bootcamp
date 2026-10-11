/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:28:28 by rodantec          #+#    #+#             */
/*   Updated: 2026/01/12 09:28:28 by rodantec         ###   ########.fr       */
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

bool Fixed::operator>(const Fixed &other) const
{
    return (_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return(_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return ( _value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return(_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_value + other._value);
    return result;
}


Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_value - other._value);
    return result;
}


Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_value * other._value) >> _base);
    return result;
}


Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_value << _base) / other._value);
    return result;
}


Fixed &Fixed::operator++(void)
{
    _value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    _value++;
    return (tmp);
}

Fixed& Fixed::operator--(void)
{
    _value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _value--;
    return (tmp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}
