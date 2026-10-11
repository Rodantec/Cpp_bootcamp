#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap has been created" << std::endl;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return (*this);
}

ClapTrap::ClapTrap(const std::string &name) :  _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap " << name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "a copy of ClapTrap has been created" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't attack (0 hp)" << std::endl;
        return ;
    }
    if(_energyPoints < 1)
    {
        std::cout << "ClapTrap " << _name << " does not have enough energy to attack (0 energyPoints)" << std::endl;
        return ;
    }
    if(_hitPoints > 0)
    {
         _energyPoints--;
         std::cout << "ClapTrap " << _name <<" attacks " << target << " causing " << _attackDamage << " points of damage!"<< std::endl;
    }
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if(_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead " << std::endl ;
        return ;
    }
    if (amount >= _hitPoints)
    {
        _hitPoints = 0 ;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damages and dies" << std::endl ;
    }
    else
    {
        _hitPoints -= amount ;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damages, and have " << _hitPoints << " hp left" << std::endl ;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't be repaired!" << std::endl;
        return;
    }
    if(_energyPoints < 1)
    {
        std::cout << "ClapTrap " << _name << " does not have enough energy to restaure (0 energyPoints)" << std::endl;
        return ;
    }
    else
    {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " restaure " << amount << " hps and have " << _hitPoints << "hps left" << std::endl ;
    }
}