#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat's default constructor called" << std::endl;
    this->type = std::string("Cat");
    this->brain = new Brain("Cat");
}

Cat::Cat(Cat const &copy)
{
    std::cout << "Cat's copy constructor called" << std::endl;
    this->type = copy.type;
    this->brain = new Brain(*copy.getBrain());
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator= (const Cat &src)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        delete this->brain;
        this->brain = new Brain(*src.getBrain());
    }
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat sound" << std::endl;
}

Brain* Cat::getBrain(void) const
{
    return (this->brain);
}