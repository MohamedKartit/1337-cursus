#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap's Default constructor called" << std::endl;
    _name = "default-ClapTrap";
    _hitpoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap's named constructor called" << std::endl;
    _name = name;
    _hitpoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor for " << _name << " called!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &op)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    if (this != &op) {
        _name = op._name;
        _hitpoints = op._hitpoints;
        _energyPoints = op._energyPoints;
        _attackDamage = op._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(std::string const &target)
{
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot attack!" << std::endl;
        return;
    }
    if (_hitpoints <= 0) {
        std::cout << "ClapTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitpoints -= amount;
    if (_hitpoints < 0)
        _hitpoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " points of damage! Remaining hit points: " << _hitpoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot repair!" << std::endl;
        return;
    }
    if (_hitpoints <= 0) {
        std::cout << "ClapTrap " << _name << " is out of hit points and cannot repair!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitpoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself, gaining " << amount 
              << " hit points. Current hit points: " << _hitpoints << std::endl;
}