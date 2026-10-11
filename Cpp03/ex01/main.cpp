#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavy");
    
    std::cout << std::endl;

    clap.attack("Scavy");
    scav.takeDamage(0);
    
    std::cout << std::endl;

    scav.attack("Clappy");
    clap.takeDamage(20);

    std::cout << std::endl;

    clap.beRepaired(10);
    scav.guardGate();

    std::cout << std::endl;

    scav.takeDamage(100);
    scav.attack("someone");

    std::cout << std::endl;

    return 0;
}