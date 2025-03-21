#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main() {
    {
    Weapon club = Weapon("crude spiked club");
    // Weapon gun = Weapon("gun");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    // bob = HumanA("Bob", gun);
    // bob.attack();
    }
    {
    Weapon club = Weapon("crude spiked club");
    // Weapon gun = Weapon("gun");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    // jim.setWeapon(gun);
    // jim.attack();
    }
    return 0;
}
