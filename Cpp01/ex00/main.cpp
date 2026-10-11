#include "Zombie.hpp"

int main(void)
{
    Zombie* heapZombie = newZombie("Heap");
    heapZombie->announce();
    delete heapZombie;
    
    randomChump("Stack");
    return 0;
}
