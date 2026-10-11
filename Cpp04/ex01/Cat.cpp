/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:49:28 by rodantec          #+#    #+#             */
/*   Updated: 2026/01/16 09:49:28 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() : Animal()
{
    _type = "Cat" ;
    std::cout << "Cat constructor called" << std::endl ;
    _brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl ;
    _brain = new Brain(*other._brain);
    *this = other ;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *_brain = *other._brain;
    }
    return (*this) ;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl ;
    delete _brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow meow" << std::endl ;
}

Brain* Cat::getBrain() const
{
    return _brain;
}