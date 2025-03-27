#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // scavtrap example
    ScavTrap scavtrap("ST-1");
    scavtrap.attack("target");
    scavtrap.guardGate();
    scavtrap.takeDamage(100);
    scavtrap.beRepaired(50);
    scavtrap.attack("target");
    scavtrap.guardGate();
    return 0;
}