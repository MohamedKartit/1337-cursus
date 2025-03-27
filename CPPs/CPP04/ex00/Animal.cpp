#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = copy.type;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

Animal& Animal::operator= (const Animal &src)
{
    if (this == &src)
        return (*this);
    this->type = src.getType();
    return (*this);
}

void Animal::makeSound(void) const
{
    std::cout << "Animal sound..." << std::endl;
}

