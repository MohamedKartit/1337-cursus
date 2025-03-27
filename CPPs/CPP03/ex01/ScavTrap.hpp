#ifndef SCARVTRAP_HPP
#define SCARVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &op);

        void attack(std::string const & target);
        void guardGate();
};

#endif