#include "WrongDog.hpp"

WrongDog::WrongDog()
{
    std::cout << "WrongDog constructor called" << std::endl;
    this->type = "WrongDog";
}

WrongDog::WrongDog(WrongDog const &copy)
{
    std::cout << "WrongDog copy constructor called" << std::endl;
    this->type = copy.type;
}

WrongDog::~WrongDog()
{
    std::cout << "WrongDog destructor called" << std::endl;
}

WrongDog& WrongDog::operator= (const WrongDog &src)
{
    if (this == &src)
        return (*this);
    this->type = src.type;
    return (*this);
}

void WrongDog::makeSound(void) const
{
    std::cout << "WrongDog sound" << std::endl;
}