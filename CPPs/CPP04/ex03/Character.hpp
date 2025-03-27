#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *inventory[4];
        AMateria *floorMaterias[100];
        int floorMateriaCount;

    public:
        Character();
        Character(const std::string &name);
        Character(const Character &copy);
        Character &operator=(const Character &src);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target); 
};

#endif