#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <cstring>

MateriaSource::MateriaSource() : index(0)
{
    // std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src)
{
    if (this != &src)
    {
        for (int i = 0; i < index; i++)
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
        index = 0;
        for (int i = 0; i < src.index; i++)
        {
            if (index < 4)
            {
                inventory[index] = src.inventory[i]->clone();
                index++;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    // std::cout << "MateriaSource Destructor called" << std::endl;
    for (int i = 0; i < index; i++)
    {
        delete inventory[i];
        inventory[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (index < 4 && m)
    {
        inventory[index] = m->clone();
        delete m;
        index++;
    }
    else if (index >= 4)
    {
        delete m;
        std::cout << "Full inventory" << std::endl;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (type != "ice" && type != "cure")
        return 0;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i]->getType() == type)
            return inventory[i]->clone();
    }
    return 0;
}


