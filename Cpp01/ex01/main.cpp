#include "Zombie.hpp"

int main(void)
{
    int N = 10;
    Zombie* horde;
    
    horde = zombieHorde(N, "HordeZombie");
    
    if (horde == NULL)
    {
        std::cout << "Failed to create zombie horde!" << std::endl;
        return 1;
    }
    
    std::cout << "\nAll zombies announcing themselves:" << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();
    }
    
    std::cout << "\nDeleting the horde..." << std::endl;
    delete[] horde;
    
    return 0;
}
