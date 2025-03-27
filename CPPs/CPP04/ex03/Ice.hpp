#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
    private:
        std::string name;
    public:
        Ice();
        Ice(const Ice &copy);
        Ice& operator=(const Ice &src);
        ~Ice();

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif