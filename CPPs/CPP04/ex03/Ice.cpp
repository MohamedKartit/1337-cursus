#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "Ice default constructor called" << std::endl;
}
Ice::Ice(const Ice &copy) : AMateria("ice")
{
    // std::cout << "Ice copy constructor called" << std::endl;
    *this = copy;
}

Ice& Ice::operator=(const Ice &src)
{
    // std::cout << "Ice copy assignment operator called" << std::endl;
    if (this != &src)
        this->type = src.type;
    return *this;
}
Ice::~Ice()
{
    // std::cout << "Ice Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    AMateria *obj = new Ice();
    return obj; 
}

void Ice::use(ICharacter &target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}