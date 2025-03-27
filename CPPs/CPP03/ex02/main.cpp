#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    FragTrap frag("FT-1");
    frag.attack("Target");
    for (int i = 0; i < 5; i++) {
        frag.highFivesGuys();
        frag.attack("Target");
        frag.takeDamage(20);
    }
    frag.beRepaired(1);
    for (int x = 0; x < 5; x++) {
        frag.attack("Target");
    }
    frag.highFivesGuys();
    return 0;
}