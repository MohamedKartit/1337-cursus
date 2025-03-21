#ifndef ZOMBIE_CPP
# define ZOMBIE_CPP
#include <iostream>

class Zombie {
    private: 
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void setName(std::string name);
        std::string getName(void);
        void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif