#include "Dog.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog" ;
    std::cout << "Dog constructor called" << std::endl ;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl ;
    Animal::operator=(other) ;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl ;
}

void Dog::makeSound() const
{
    std::cout << " Bark bark bark" << std::endl ;
}