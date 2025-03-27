#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(Dog const &copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = copy.type;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator= (const Dog &src)
{
    if (this == &src)
        return (*this);
    this->type = src.getType();
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog sound..." << std::endl;
}