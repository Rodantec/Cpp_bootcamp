/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:27:56 by rodantec          #+#    #+#             */
/*   Updated: 2026/01/12 09:27:56 by rodantec         ###   ########.fr       */
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