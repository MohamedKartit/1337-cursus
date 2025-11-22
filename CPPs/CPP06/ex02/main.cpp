#include "Base.hpp"
#include <iostream>

int main()
{
    Base* ptr = generate();
    
    std::cout << "Identifying using pointer: ";
    identify(ptr);
    
    std::cout << "Identifying using reference: ";
    identify(*ptr);
    
    delete ptr;
    return 0;
} 