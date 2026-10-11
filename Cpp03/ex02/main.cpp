#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavy");
    FragTrap frag("Fraggy");

    std::cout << std::endl;

    clap.attack("Scavy");
    scav.attack("Fraggy");
    frag.attack("Clappy");

    std::cout << std::endl;

    clap.takeDamage(30);
    scav.takeDamage(20);
    frag.takeDamage(10);

    std::cout << std::endl;

    clap.beRepaired(5);
    scav.beRepaired(10);
    frag.beRepaired(15);

    std::cout << std::endl;

    scav.guardGate();
    frag.highFivesGuys();

    std::cout << std::endl;

    frag.takeDamage(100);
    frag.attack("someone");

    std::cout << std::endl;

    return 0;
}