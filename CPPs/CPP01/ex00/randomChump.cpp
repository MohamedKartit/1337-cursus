#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie zombie = Zombie();
    zombie.setName(name);
    zombie.announce();
}