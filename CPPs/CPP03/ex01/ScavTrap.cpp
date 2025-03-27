#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap's named constructor called" << std::endl;
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap's copy constructor called" << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor for " << _name << " called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &op)
{
    std::cout << "ScavTrap assignation operator called" << std::endl;
    if (this != &op) {
        _name = op._name;
        _hitpoints = op._hitpoints;
        _energyPoints = op._energyPoints;
        _attackDamage = op._attackDamage;
    }
    return *this;
}

void ScavTrap::attack(std::string const &target)
{
    if (_energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " is out of energy and cannot attack!" << std::endl;
        return;
    }
    if (_hitpoints <= 0) {
        std::cout << "ScavTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
}
