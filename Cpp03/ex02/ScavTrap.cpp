#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitPoints = 100 ;
    this->_energyPoints = 50 ;
    this->_attackDamage = 20 ;
    std::cout << "ScavTrap " << _name << " has been created" << std::endl ;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->_hitPoints = 100 ;
    this->_energyPoints = 50 ;
    this->_attackDamage = 20 ;
    std::cout << "ScavTrap " << _name << " has been created" << std::endl ;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << other._name << " has been copied" << std::endl ;
    *this = other;
}
ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other) ;
    std::cout << "ScavTrap assignement operator called" << std::endl ;
    return (*this) ;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(_hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " is dead and can't attack (0 hp)" << std::endl;
        return ;
    }
    if(_energyPoints < 1)
    {
        std::cout << "ScavTrap " << _name << " does not have enough energy to attack (0 energyPoints)" << std::endl;
        return ;
    }
    if(_hitPoints > 0)
    {
         _energyPoints--;
         std::cout << "ScavTrap " << _name << " attacks with a lot of strenght " << target << " causing " << _attackDamage << " points of damage!"<< std::endl;
    }
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
