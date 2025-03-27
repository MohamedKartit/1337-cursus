#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap's default constructor called" << std::endl;
    _hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap's named constructor called" << std::endl;
    _hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = copy;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor for " << _name << " called!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &op)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    if (this != &op) {
        _name = op._name;
        _hitpoints = op._hitpoints;
        _energyPoints = op._energyPoints;
        _attackDamage = op._attackDamage;
    }
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}