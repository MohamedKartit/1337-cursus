#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;

    public:
        Dog();
        Dog(Dog const &copy);
        ~Dog();
        Dog&    operator= (const Dog &src);

        void	makeSound(void) const;
        Brain*	getBrain(void) const;
};

#endif