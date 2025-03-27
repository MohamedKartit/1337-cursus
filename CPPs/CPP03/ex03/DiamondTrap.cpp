#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    _name = "defualt-DiamondTrap";
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap " << this->_name << " constructed! with " << "hits: " << this->_hitpoints << ", DMG: " << this->_attackDamage << ", Energy: " << this->_energyPoints << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap " << this->_name << " constructed! with " << "hits: " << this->_hitpoints << ", DMG: " << this->_attackDamage << ", Energy: " << this->_energyPoints << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy._name + "_clap_name"), ScavTrap(copy._name), FragTrap(copy._name)
{
    std::cout << "DiamondTrap's copy constructor called" << std::endl;
    *this = copy;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &op)
{
    std::cout << "DiamondTrap assignation operator called" << std::endl;
    if (this != &op)
    {
        _name = op._name;
        _hitpoints = op._hitpoints;
        _energyPoints = op._energyPoints;
        _attackDamage = op._attackDamage;
    }
    return *this;
}

void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap " << this->_name << " is " << ClapTrap::_name << std::endl;
}