#ifndef ZOMBIE_CPP
# define ZOMBIE_CPP

#include <iostream>
#include <string>

class Zombie {
    private: 
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void setName(std::string name);
        std::string getName(void);
        void announce();
};

Zombie *zombieHorde(int N, std::string name);

#endif