#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("CT-1");

    clapTrap.attack("enemy");
    clapTrap.attack("enemy");
    clapTrap.beRepaired(30);
    clapTrap.attack("enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(30);
    clapTrap.takeDamage(60);
    clapTrap.attack("enemy");
    clapTrap.attack("enemy");
    clapTrap.attack("enemy");
    clapTrap.attack("enemy");
    clapTrap.attack("enemy");
    clapTrap.attack("enemy");

    ClapTrap cp_2;
    cp_2 = clapTrap;
    cp_2.attack("enemy");
    return 0;
}