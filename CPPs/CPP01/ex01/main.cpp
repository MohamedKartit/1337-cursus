#include "Zombie.hpp"

int main() {
    Zombie *zombies = zombieHorde(5, "Zombie");
    for (int i = 0; i < 5; i++) {
        std::cout << "Zombie " << i + 1 << ": ";
        zombies[i].announce();
    }
    delete[] zombies;
    return 0;
}