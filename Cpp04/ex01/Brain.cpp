/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:49:22 by rodantec          #+#    #+#             */
/*   Updated: 2026/01/16 09:49:22 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}
Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain &other)
{
    std::cout << "Brain assignment operator called" << std::endl ;
    for(int i = 0; i < 100; i++)
    {
        _ideas[i] = other._ideas[i] ;
    }
    return (*this) ;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl ;
}

void Brain::setIdea(int index, const std::string &idea)
{
    if(index >= 0 && index < 100)
        _ideas[index] = idea ;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (_ideas[index]) ;
    return "" ;
}