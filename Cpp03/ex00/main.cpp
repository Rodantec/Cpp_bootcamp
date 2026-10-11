#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trappy");

    std::cout << std::endl;

    clap1.attack("Trappy");
    clap2.takeDamage(0);

    std::cout << std::endl;

    clap2.attack("Clappy");
    clap1.takeDamage(3);

    std::cout << std::endl;

    clap1.beRepaired(5);

    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
    {
        clap1.attack("dummy");
    }

    std::cout << std::endl;

    clap1.beRepaired(1);

    std::cout << std::endl;

    clap2.takeDamage(10);
    clap2.attack("someone");
    clap2.beRepaired(5);

    std::cout << std::endl;

    return 0;
}