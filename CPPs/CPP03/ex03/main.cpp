#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    DiamondTrap diamondTrap("pooP");
    diamondTrap.attack("target");
    for (int i = 0; i < 5; i++) {
        diamondTrap.attack("target");
    }
    diamondTrap.attack("target");
    for (int i = 0; i < 5; i++) {
        diamondTrap.beRepaired(10);
    }
    diamondTrap.whoAmI();
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    diamondTrap.attack("target");
    diamondTrap.takeDamage(500);
    diamondTrap.attack("target");
    diamondTrap.beRepaired(500);
    diamondTrap.attack("target");
    return 0;
}