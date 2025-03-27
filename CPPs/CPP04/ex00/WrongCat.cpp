#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &copy)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = copy.type;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator= (const WrongCat &src)
{
    if (this == &src)
        return (*this);
    this->type = src.type;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat sound" << std::endl;
}