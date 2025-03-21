#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "default constrcutor called" << std::endl;
}

Zombie::~Zombie() {
    std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce() {
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

std::string Zombie::getName() {
    return this->name;
}
