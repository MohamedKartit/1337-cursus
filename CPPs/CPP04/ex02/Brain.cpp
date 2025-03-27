#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain's default constructor called" << std::endl;
    for (size_t i = 0; i < 100; i++)
        this->ideas[i] = std::string(THOUGHT);
}

Brain::Brain(std::string type)
{
    std::cout << "Brain's named constructor called" << std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        if (type == "Cat")
            this->ideas[i] = std::string(CAT_THOUGHT);
        else if (type == "Dog")
            this->ideas[i] = std::string(DOG_THOUGHT);
        else
            this->ideas[i] = std::string(THOUGHT);
    }
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain's copy constructor is called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}


Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator= (const Brain &src)
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this == &src)
        return (*this);
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    return (*this);
}

const std::string Brain::getIdea(void) const
{
    return (this->ideas[0]);
}

void Brain::setIdea(std::string const idea)
{
    this->ideas[0] = idea;
}