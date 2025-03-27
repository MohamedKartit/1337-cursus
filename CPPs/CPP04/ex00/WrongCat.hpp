#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const &copy);
        ~WrongCat();

        WrongCat& operator= (const WrongCat &src);
        void	makeSound(void) const;
};

#endif