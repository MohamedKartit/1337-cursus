#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define THOUGHT     "I think therefore I am"
# define CAT_THOUGHT "Meow Meow !"
# define DOG_THOUGHT "BARKS BARKS !"

class Brain
{
    protected :
        std::string ideas[100];

    public :
        Brain();
        Brain(Brain const &copy);
        ~Brain();
        Brain(std::string type);
        Brain& operator= (const Brain &src);

        const std::string getIdea() const;
        void setIdea(std::string const idea);
};

#endif