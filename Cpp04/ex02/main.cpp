/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:50:15 by rodantec          #+#    #+#             */
/*   Updated: 2026/01/16 09:50:15 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    
    std::cout << "\n=== Creating array of Animals (Dog and Cat only) ===" << std::endl;
    const Animal* animals[4];
    
    for (int i = 0; i < 2; i++)
    {
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    
    for (int i = 2; i < 4; i++)
    {
        animals[i] = new Cat();
        std::cout << std::endl;
    }
    
    std::cout << "=== Testing sounds ===" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n=== Testing deep copy ===" << std::endl;
    Dog original;
    original.getBrain()->setIdea(0, "Chase the cat!");
    original.getBrain()->setIdea(1, "Fetch the ball!");
    
    std::cout << "\nOriginal dog brain idea 0: " << original.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\nCreating copy..." << std::endl;
    Dog copy = original;
    
    std::cout << "\nCopy dog brain idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\nModifying original..." << std::endl;
    original.getBrain()->setIdea(0, "Sleep all day!");
    
    std::cout << "Original dog brain idea 0: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy dog brain idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
    
    if (original.getBrain() != copy.getBrain())
        std::cout << "✓ Deep copy successful!" << std::endl;
    
    std::cout << "\n=== Deleting array of Animals ===" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete animals[i];
        std::cout << std::endl;
    }
    
    std::cout << "=== End of program ===" << std::endl;
    
    return 0;
}
