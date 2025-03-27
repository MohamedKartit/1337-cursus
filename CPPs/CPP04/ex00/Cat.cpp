#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(Cat const &copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = copy.type;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &src)
{
    if (this == &src)
        return (*this);
    this->type = src.type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat sound..." << std::endl;
}