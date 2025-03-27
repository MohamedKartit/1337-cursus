#include "Character.hpp"
#include <iostream>
#include <cstring>

Character::Character() : name("Default"), floorMateriaCount(0)
{
    std::memset(inventory, 0, sizeof(inventory));
    std::memset(floorMaterias, 0, sizeof(floorMaterias));
}

Character::Character(const std::string& name) : name(name), floorMateriaCount(0)
{
    std::memset(inventory, 0, sizeof(inventory));
    std::memset(floorMaterias, 0, sizeof(floorMaterias));
}

Character::Character(const Character& copy)
{
    floorMateriaCount = 0;
    std::memset(floorMaterias, 0, sizeof(floorMaterias));
    *this = copy;
}

Character& Character::operator=(const Character& src)
{
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
        for (int i = 0; i < floorMateriaCount; i++)
        {
            delete floorMaterias[i];
            floorMaterias[i] = NULL;
        }
        floorMateriaCount = 0;
        name = src.name;
        for (int i = 0; i < 4; i++)
        {
            if (src.inventory[i])
                inventory[i] = src.inventory[i]->clone();
        }
        for (int i = 0; i < src.floorMateriaCount; i++)
        {
            if (floorMateriaCount < 100)
            {
                floorMaterias[floorMateriaCount] = src.floorMaterias[i]->clone();
                floorMateriaCount++;
            }
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
        inventory[i] = NULL;
    }
    for (int i = 0; i < floorMateriaCount; i++)
    {
        delete floorMaterias[i];
        floorMaterias[i] = NULL;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        if (floorMateriaCount < 100)
        {
            floorMaterias[floorMateriaCount] = inventory[idx];
            floorMateriaCount++;
            inventory[idx] = NULL;
        }
        else
            std::cout << "Floor is full. Cannot unequip more Materias." << std::endl;
    }
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
    std::cout << "Inventory is full. Cannot equip more Materias." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
        inventory[idx]->use(target);
}