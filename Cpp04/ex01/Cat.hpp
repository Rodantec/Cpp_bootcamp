/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:49:30 by rodantec          #+#    #+#             */
/*   Updated: 2026/01/16 09:49:30 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private :
        Brain *_brain ;
    public :
        Cat() ;
        Cat(const Cat &other) ;
        Cat& operator=(const Cat &other) ;
        ~Cat() ;

        void makeSound() const ;
        Brain* getBrain() const;
};

#endif