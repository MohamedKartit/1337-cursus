#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog's default constructor called" << std::endl;
    this->type = std::string("Dog");
    this->brain = new Brain("Dog");
}

Dog::Dog(Dog const &copy)
{
    std::cout << "Dog's copy constructor called" << std::endl;
    this->type = copy.type;
    this->brain = new Brain(*copy.getBrain());
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator= (const Dog &src)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        delete this->brain;
        this->brain = new Brain(*src.getBrain());
    }
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog sound" << std::endl;
}

Brain* Dog::getBrain(void) const
{
    return (this->brain);
}