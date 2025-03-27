#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
    // std::cout << "AMateria default constructor called" << std::endl;
}
AMateria::AMateria(const AMateria& copy)
{
    // std::cout << "AMateria copy constructor called" << std::endl;
    *this = copy;
}

AMateria& AMateria::operator=(const AMateria& src)
{
    // std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this != &src)
        this->type = src.type;
    return *this;
}
AMateria::AMateria(const std::string &type) : type(type)
{
    // std::cout << "AMateria param constructor called" << std::endl;
}
AMateria::~AMateria()
{
    // std::cout << "AMateria Destructor called" << std::endl;
}

std::string const & AMateria::getType() const  //Returns the materia type
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}