/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:48:18 by rodantec          #+#    #+#             */
/*   Updated: 2026/01/16 09:48:18 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string _type;

    public:
    Animal() ;
    Animal(const Animal &other) ;
    Animal& operator=(const Animal &other) ;
    virtual ~Animal();

    virtual void makeSound() const ;
    std::string getType() const ;
    
};

#endif