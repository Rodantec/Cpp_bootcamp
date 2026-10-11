#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100 ;
    _energyPoints = 100 ;
    _attackDamage = 30 ;
    std::cout << "FragTrap " << _name << " has been created" << std::endl ;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    _hitPoints = 100 ;
    _energyPoints = 100 ;
    _attackDamage = 30 ;
    std::cout << "FragTrap " << _name << " has been created" << std::endl ;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap " << other._name << " has been created" << std::endl ;
    *this = other ;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap assignment operator called" << std::endl ;
    ClapTrap::operator=(other);
    return (*this) ;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " has been destroyed" << std::endl ;
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests for an high five" << std::endl;
}